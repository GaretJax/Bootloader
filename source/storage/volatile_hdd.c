/*
 * volatile_hdd.c
 *
 *	Simulate the volatile memory using a file to save the data
 *  Created on: Mai 8, 2010
 *      Author: Elias Medawar
 *
 */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "./volatile.h"

int vstorage_read(char * buffer,const void * address, int length){
    FILE* fichier = fopen("./hdd.ram", "rb+");
    fseek(fichier,address, SEEK_SET);
    fread ( buffer, 1, length,fichier );
    fclose(fichier);    
    return 0;
}
int vstorage_write(const char * buffer, void * address, int length){
        int cnt = count();
        FILE* fichier = fopen("./hdd.ram", "rb+");
        if((address+length)>cnt ){
            int nb = address+length -cnt;
            fseek(fichier, 0, SEEK_END);
            while(nb>0){
                fputc(' ',fichier);
                nb--;
            } 
        }
        fseek(fichier,0L, SEEK_SET);
        
        fseek(fichier,address, SEEK_SET);
        fwrite(buffer, 1,length,fichier);
        fclose(fichier);    
        return 0;
}
int count() {
    int             count = 0;  /* number of characters seen */
    int             ch;
    FILE* fichier = fopen("./hdd.ram", "ab+");
    if (fichier == NULL) {
        return -1;
    }
    ch = fgetc(fichier);
    while (ch != EOF) {
        ch = fgetc(fichier);
        ++count;
    }
    fclose(fichier);
    return count;
}

