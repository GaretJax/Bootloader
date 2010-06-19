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
//#include "../storage/persistent.h"

/**
 * Maximum length for an application name identifier
 */
#define APP_NAME_LENGTH 50

/**
 * Defines the different available configuration directives. This structure is
 * saved and loaded to flash memory with the methods config_load() and config_save()
 */
struct Config {
	int app_0_flash_address;
	int app_1_flash_address;
	char app_0_name[APP_NAME_LENGTH];
	char app_1_name[APP_NAME_LENGTH];
	int app_memory_address;

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

