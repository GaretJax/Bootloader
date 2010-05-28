/*
 *  interrupts.c
 *  Bootloader
 *
 *  Created by Jonathan Stoppani on 5/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "interrupts.h"

volatile interrupt_handler * VBR = (interrupt_handler *) VBR_ADDRESS;

void install_interrupt(interrupt_handler handler, unsigned short index) {
	VBR[index] = handler;
}
