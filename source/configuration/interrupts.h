#pragma once

/**
 * The base address of the vector table.
 */
#define VBR_ADDRESS 0x10000

/**
 * The length of the vector base register, or the maximum allowed index to store
 * an interrupt handler in the register.
 */
#define VBR_INTERRUPT_COUNT 256

/**
 * The prototype of an interrupt handler.
 */
typedef void (* InterruptHandler)();

/**
 * Installs the given interrupt to the chosen index.
 *
 * @pre the index paramter must be smaller than VBR_INTERRUPT_COUNT.
 */
void install_interrupt(InterruptHandler handler, unsigned short index);
