/*
 * test_volatile.c
 *
 *  Created on: 20 juin 2010
 *      Author: Elias Medawar
 */

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
