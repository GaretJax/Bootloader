#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "./volatile.h"
char VS_RAM[256000];
int vstorage_read(char * buffer,const void * relativeADR, int length){
    char *add = VS_RAM + (int)relativeADR;
    memcpy ( buffer, add, length);
    return 0;
}
int vstorage_write(const char * buffer, void * relativeADR, int length){ 
    char *dst  =VS_RAM + (int)relativeADR; 
    memcpy (dst, buffer, length);
    return 0;
}
int main5(){
    void * add = (void *)0x000A;
    char te[] = "Valeur en mémoire à l'adresse 10";
    vstorage_write(te,add,strlen(te)+1);
    add = (void *)0x002A;
    char te2[] = "Valeur à l'adresse 42";
    add = (void *)0x000A;
    vstorage_read(te2,add,34);
    printf("Read %s",te2);
    return 0;
}
