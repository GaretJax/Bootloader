/*
 * test_volatile_hdd.c
 *	A smal test method for the volatile_hdd.c fille
 *  Created on: 20 juin 2010
 *      Author: Medawar Elias
 *	//TODO: Complete the tests
 */
int main4(){

    void * add = (void *)0x000A;
    char te[] = "Valeur en mémoire à l'adresse 1";
    vstorage_write(te,add,strlen(te)+1);
    add = (void *)0x002A;
    char te2[] = "Valeur à l'adresse 42";
    add = (void *)0x000A;
    vstorage_read(&te2,add,strlen(te2)+1);
    printf("Read %s",te2);
    return 0;
}
