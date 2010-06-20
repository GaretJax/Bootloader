/*
 * manager_local.c
 *	The application manager on a PC.
 *  Created on: Jun 11, 2010
 *      Author: Elias Medawar
 * 	//TODO: Test this module
 */
#pragma once
#include "../storage/volatile.h"
#include "../storage/persistent.h"
#include "../configuration/registry.h"

enum APPLICATION_ID crntLoaded;

int application_load(APPLICATION_ID appid) {
	crntLoaded = appid;
}

int application_run(){
	printf("Application  %s is running", config.apps_config[crntLoaded].app_name);
	return 0;

}

int application_add(enum APPLICATION_ID appid, const char * name,
		const char * buffer, int length) {
	pstorage_write(buffer, s_config[appid], length);
	config.apps_config[appid].length = length;
	config.apps_config[appid].isEnable = true;
	strcpy ( &config.apps_config[appid].app_name, name);
}

int application_remove(enum APPLICATION_ID appid) {
	config.apps_config[appid].isEnable = false;
}

int application_rename(enum APPLICATION_ID appid, const char * name){
	strcpy ( &config.apps_config[appid].app_name, name);
}
