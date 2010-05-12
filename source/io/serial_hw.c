/*
 *  hw.c
 *  Bootloader
 *
 *  Created by Jonathan Stoppani on 4/30/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "serial_hw.h"

#define BUFFER_SIZE 1<<8

volatile struct QSM * qsm_register = (struct QSM *) QSM_BASE_ADDRESS;