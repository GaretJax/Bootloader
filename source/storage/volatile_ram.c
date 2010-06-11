#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "./volatile.h"
char * RAM_BASE = (char *)0x100000;
int vstorage_read(char * buffer,const void * relativeADR, int length){
    char *add = RAM_BASE + (long)relativeADR;
    memcpy ( buffer, add, length);
    return 0;
}
int vstorage_write(const char * buffer, void * relativeADR, int length){ 
    char * dst  = RAM_BASE + (long)relativeADR; 
    memcpy (dst, buffer, length);
    return 0;
}
