#include <stdio.h>
#include <stdlib.h>


#include "persistent.h"


int main (int argc, const char * argv[]) {
	char from1030[] = "ABCDEXCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABDFGHZZZZZZ";
	char from10[] = "XXXXXXXXXX";
	//char* to = malloc(10);
	//char* to = (char*)0x0u;
	
	char result5[5];	
	char result2[2];	
	char result1024[1024];
	char result1027[1027];
	
	pstorage_write(from10, 0, 5);
    pstorage_read(result5, 0, 10);
    printf(result5);


	pstorage_write(from10, 20, 2);
    pstorage_read(result2, 20, 2);
    printf(result2);
    
   	pstorage_write(from1030, 1, 1024);
    pstorage_read(result1024, 20, 1024);
    printf(result1024);
    
    pstorage_write(from1030, 1, 1027);
    pstorage_read(result1027, 20, 1027);
    printf(result1027);
    
    return 0;
}

