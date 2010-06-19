/*
 * manager_local.c
 *
 *  Created on: Jun 11, 2010
 *      Author: Elias Medawar
 *
 * 	//TODO: Test this module
 */
#pragma once
#include "../storage/volatile.h"
#include "../storage/persistent.h"
#include "../configuration/registry.h"

enum APPLICATION_ID crntLoaded;

typedef void(* Application);

int application_load(APPLICATION_ID appid) {
	crntLoaded = appid;
	if (config.apps_config[crntLoaded].isEnable) {
		pstorage_read(APP_BASE_ADDRESS,
				config.apps_config[crntLoaded].flashBlock,
				config.apps_config[crntLoaded].length);
		return 0;
	} else {
		printf("Error the application is not enable ");
		return -1;
	}
}

int application_run() {
	 Application app = (Application)(APP_BASE_ADDRESS);
	 app();
	 return 0;
}

int application_add(enum APPLICATION_ID appid, const char * name,
		const char * buffer, int length) {
	pstorage_write(buffer, s_config[appid], length);
	config.apps_config[appid].length = length;
	config.apps_config[appid].isEnable = true;
	strcpy(&config.apps_config[appid].app_name, name);
}

int application_remove(enum APPLICATION_ID appid) {
	config.apps_config[appid].isEnable = false;
}

int application_rename(enum APPLICATION_ID appid, const char * name) {
	strcpy(&config.apps_config[appid].app_name, name);
}
