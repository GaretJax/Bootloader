/*
 * volatile.c
 *
 *	Implementation to use on the microchip
 *  Created on: Mai 8, 2010
 *      Author: Elias Medawar
 *
 */
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "./volatile.h"

int vstorage_read(char * buffer,const void * relativeADR, int length){
    char *add = RAM_BASE_ADDRESS + (int)relativeADR;
    memcpy ( buffer, add, length);
    return 0;
}
int vstorage_write(const char * buffer, void * relativeADR, int length){ 
    char *dst  =RAM_BASE_ADDRESS + (int)relativeADR;
    memcpy (dst, buffer, length);
    return 0;
}

