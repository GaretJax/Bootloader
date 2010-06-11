/*
 *  hw.c
 *  Bootloader
 *
 *  Created by Jonathan Stoppani on 4/30/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdbool.h>
#include "serial_hw.h"
#include "serial.h"
#include "hardware.h"
#include "interrupts.h"

/**
 * The receive buffer size
 */
#define BUFFER_SIZE 1<<8

/**
 * The index where to place the interrupt handler in the VBR
 */
#define SERIAL_INTERRUPT_HANDLER_INDEX 64

/**
 * The level at which the interrupts of the serial interface are fired
 */
#define SERIAL_INTERRUPT_LEVEL 3

volatile struct QSM * qsm = (struct QSM *) QSM_BASE_ADDRESS;

static unsigned int start = 0;
static unsigned int stop  = 0;
static unsigned char input_buffer[BUFFER_SIZE];

#pragma interrupt on

static void serial_hw_interrupt_handler() {
	bool error;
	
	while (qsm->SCSR & RDRF) {
		/* Register contains new data */
		
		if ((BUFFER_SIZE + stop - start) % BUFFER_SIZE == BUFFER_SIZE - 1) {
			/* Buffer is full */
			return;
		}
		
		/* Read the partiy error flag before the data, to prevent that we read the flag
		 * for the wrong data set
		 */
		error = qsm->SCSR & PF;
		
		/* Save to the buffer */
		input_buffer[stop] = (unsigned char) qsm->SCDR;
		
		if (!error) {
			/* Update the index (only if there were no errors) */
			stop = (stop + 1) % BUFFER_SIZE;			
		}
	}
}

static void serial_hw_init(unsigned int baudrate, bool parity_enabled, bool parity) {
	qsm->QIVR = SERIAL_INTERRUPT_HANDLER_INDEX;
	
	/* Set the interrupt level */
	qsm->QILR &= ~ILSCI_MASK;
	qsm->QILR |= SERIAL_INTERRUPT_LEVEL << ILSCI;
	
	/* Clear the SQPI interrupt level */
	qsm->QILR &= ~ILQSPI_MASK;
	
	/* Calculate and set the baudrate */
	qsm->SCCR0 = (SYSTEM_CLOCK * 10 / (32 * baudrate) + 5) / 10;
	
	/* Enable the reception interrupt, the transmission and the reception */
	qsm->SCCR1 = RIE | TE | RE | (parity ? PT : 0) | (parity_enabled ? PE|M : 0);
	
	/* Install the interrupt handler for the serial interface */
	install_interrupt(serial_hw_interrupt_handler, SERIAL_INTERRUPT_HANDLER_INDEX);
}

int serial_init(const void * config_struct) {
	const struct SerialConfig * config = (const struct SerialConfig *) config_struct;
	
	serial_hw_init(config->baudrate, config->parity != DISABLED, config->parity == ODD);
	
	return 0;
}

char serial_readchar() {
	char c;
	
	/* Wait for a character to be present */
	while (start == stop) {}
	
	/* Read the character */
	c = input_buffer[start];
	
	/* Set the new buffer */
	start = (start + 1) % BUFFER_SIZE;
	
	return c;
}

int serial_buffered_chars_count() {
	return (stop - start + BUFFER_SIZE) % BUFFER_SIZE;
}

int serial_readline(char * buffer, const int buf_size) {
	int length = 0;
	char c = 0;
	
	while (c != '\n') {
		/* Read the next char */
		c = serial_readchar();
		
		/* If we haven't reached the max length yet */
		if (length < buf_size) {
			buffer[length] = c;
			length++;
		}
	}
	
	/* Delete the last char if it is a new line */
	if (buffer[length] == '\n') {
		length--;
	}
	
	/* Delete the last char if it is a carriage return */
	if (buffer[length] == '\r') {
		length--;
	}
	
	/* Terminate the string */
	buffer[length] = 0;
	
	return length;
}

void serial_writechar(const char c) {
	/* Wait for the register to be ready */
	while (!(qsm->SCSR & TDRE)) {}
	
	/* Write the character */
	qsm->SCDR = c;
}

int serial_write(const char * buffer) {
	int length = 0;
	
	while (buffer[length]) {
		serial_writechar(buffer[length]);
		length++;
	}
	
	return length;
}






