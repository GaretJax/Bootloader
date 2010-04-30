#include <stdio.h> 
#include "storage/volatile.h"
int vstorage_read(char * buffer,const void * address, int length){
    memcpy ( buffer, address, length);
    return 0;
}
int vstorage_write(const char * buffer, void * address, int length){
    memcpy ( address, buffer, length);
}
