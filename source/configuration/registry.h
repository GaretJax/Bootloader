/**
 * @file configuration/registry.h
 *
 * This module allows to store to and retrieve configuration values from a
 * persistent storage device. It uses the storage/persistent.h interface for all
 * read/write operations.
 *
 * @todo  Define the values of config.
 */


#pragma once
#include "../storage/persistent.h"
#include <stdbool.h>
//#include "../storage/persistent.h"

/**
 * Maximum length for an application name identifier
 */
#define APP_NAME_LENGTH 50


/**
 * Defines the different available configuration directives. This structure is
 * saved and loaded to flash memory with the methods config_load() and config_save()
 */

/* The prams of an aplication*/
struct APP_CONFIG {
	int flashBlock;/* The block where the application is saved in the flash memory*/
	char app_name[APP_NAME_LENGTH];
	int length;
	bool isEnable;
};
struct Config {
	struct APP_CONFIG apps_config[] = {
			{ 1 , {'A','p','1'} ,0,false},
			{ 10 , {'A','p','2'},0,false}
	};
};

extern struct Config config;


/**
 * Reads a stored Config struct out of the flash memory and updates config.
 *
 *
 * @return  0 if the value was read correctly, a negative error code otherwise.
 */
int config_load();


/**
 * Saves the actual Config struct into the flash memory.
 *
 * @return  0 if the value was set correctly, a negative error code otherwise.
 */
int config_save();

