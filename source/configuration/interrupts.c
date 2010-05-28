/*
 *  interrupts.c
 *  Bootloader
 *
 *  Created by Jonathan Stoppani on 5/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "interrupts.h"

volatile InterruptHandler * VBR = (InterruptHandler *) VBR_ADDRESS;

void install_interrupt(InterruptHandler handler, unsigned short index) {
	VBR[index] = handler;
}