/*
 * registry.c
 *
 *  Created on: Jun 11, 2010
 *      Author: yves
 */

#include "registry.h"


int config_save() {
	int res = pstorage_write(keys, 0, sizeof(keys));
	return res;
}

int config_load() {
	int res = pstorage_read(keys, 0, sizeof(keys));
	return res;
}

