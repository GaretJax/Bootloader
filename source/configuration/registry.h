/**
 * @file configuration/registry.h
 *
 * This module allows to store to and retrieve configuration values from a
 * persistent storage device. It uses the storage/persistent.h interface for all
 * read/write operations.
 *
 * @todo  Define the values in the \c CONFIG_KEY enum.
 * @todo  Should we make this interface more generic and not define the config
 *        keys using enum values? This woul allow for non hard coded keys but
 *        we loose compile-time error checking.
 *        If we change the interface in the described way, there will be the
 *        need for a \c config_clear function.
 * @todo  The two get/set functions are very generic and involve a relatively
 *        large amount of code to be used, wouldn't it be better to define the
 *        different types of the configuration directives (mainly strings and
 *        ints) and to offer type-specific getters and setters (i.e.
 *        \c config_get_int)?
 */


#pragma once
#include "../storage/persistent.h"


/**
 * Defines the different available configuration directives. This keys can be
 * used to get or set configuration values with the \c config_get and
 * \c config_set functions.
 */
enum CONFIG_KEY {
    DUMMY_CONFIG_KEY
};


/**
 * Reads the value identified by \a key argument from the config registry
 * and writes it to the memory area pointed to by \a buffer.
 *
 * @param[in]  key     The key of the configuration directive to read.
 * @param[out] buffer  The pointer to the memory area to which the value has
 *                     to be written.
 *
 * @return  0 if the value was read correctly, a negative error code otherwise.
 */
int config_get(enum CONFIG_KEY key, void * buffer);


/**
 * Sets the value identified by \a key to the content of \a buffer.
 *
 * @param[in] key     The key of the configuration directive to read.
 * @param[in] buffer  The pointer to the memory area from which the value has
 *                    to be read.
 *
 * @return  0 if the value was set correctly, a negative error code otherwise.
 */
int config_set(enum CONFIG_KEY key, const void * buffer);

