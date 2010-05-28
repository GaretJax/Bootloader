/*
 *  timer.c
 *  Bootloader
 *
 *  Created by Jonathan Stoppani on 5/28/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "timer.h"
#include "interrupts.h"
#include "hardware.h"

/**
 * The index where to place the interrupt handler in the VBR
 */
#define PERIODIC_INTERRUPT_HANDLER_INDEX 64

/**
 * The level at which the interrupts of the periodic timer are fired
 */
#define PERIODIC_INTERRUPT_LEVEL 2


volatile struct Timer * timer = (struct Timer *) TIMER_BASE_ADDRESS;

InterruptHandler currentHandler = 0;
unsigned int currentInterval = -1;
unsigned int currentTime = 0;

#pragma interrupt on

void periodic_interrupt_handler() {
	currentTime += PERIODIC_INTERRUPT_MIN_GRANULARITY;
	
	if (currentInterval >= 0 && currentTime >= currentInterval) {
		currentTime -= currentInterval;
		
		if (currentHandler != 0) {
			currentHandler();
		}
	}
}

void install_periodic_interrupt(InterruptHandler handler, unsigned int interval) {
	currentHandler = handler;
	currentInterval = interval;
	currentTime = 0;
	
	// Register the interrupt handler
	install_interrupt(periodic_interrupt_handler, PERIODIC_INTERRUPT_HANDLER_INDEX);
	
	// Set the interrupt level
	timer->PICR &= ~PIRQL_MASK;
	timer->PICR |= PERIODIC_INTERRUPT_LEVEL << PIRQL;
	
	// Set the interrupt vector index
	timer->PICR &= ~PIV_MASK;
	timer->PICR |= PERIODIC_INTERRUPT_HANDLER_INDEX << PIV;
	
	// Calculate and set the prescaling and the modulus
	char modulus = (PERIODIC_INTERRUPT_MIN_GRANULARITY * EXTAL_FREQUENCY) / (1000 * 4 * 1);
	
	timer->PITR = 0;
	timer->PITR  = modulus << PTM;
}

void uninstall_periodic_interrupt() {
	timer->PICR = 0;
	timer->PITR = 0;
	currentHandler = 0;
	currentInterval = -1;
}


