#pragma once

#include "interrupts.h"

/**
 * The granularity of the timer
 */
#define PERIODIC_INTERRUPT_MIN_GRANULARITY 20

#define TIMER_BASE_ADDRESS 0xFFFA22

enum PICR {
	PIRQL      = 8,
	PIRQL_MASK = 0x7 << PIRQL,
	PIV        = 0,
	PIV_MASK   = 0xFF << PIV
};

enum PITR {
	PTP	     = 1<<8,
	PTM      = 0,
	PTM_MASK = 0xFF << PTM,
};


struct Timer {
	unsigned short int PICR;
	unsigned short int PITR;
};


/**
 * Register an interrupt handler to be fired at periodic intervals. Only one
 * handler can be registered at each given moment.
 *
 * Please note that the minimum granularity of this timer is defined by the
 * <code>PERIODIC_INTERRUPT_MIN_GRANULARITY</code> macro.
 *
 * @param[in]  handler  The interrupt handler to be fired at the given interval.
 * @param[in]  interval  The interval (in milliseconds) at which the interrupt
 *						 handler has to be fired.
 */
void install_periodic_interrupt(InterruptHandler handler, unsigned int interval);

/**
 * Removes a precedently installed periodic interrupt handler
 */
void uninstall_periodic_interrupt();