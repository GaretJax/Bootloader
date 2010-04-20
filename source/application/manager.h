/**
 * @file application/manager.h
 *
 * Application management utilitites. This functions allow to run, add and
 * manage existing applications.
 *
 * @todo  How can we read the name of a given application? Should we provide a 
 *        function here or do we read the value directly from the configuration
 *        registry?
 */


#pragma once
#include "../storage/persistent.h"
#include "../storage/volatile.h"
#include "../configuration/registry.h"


/**
 * The different IDs given to the application which can possibly be hosted on
 * the target system.
 * The number of values in the enumeration gives the maximum number of
 * application which can coexist on the target.
 */
enum APPLICATION_ID {
    APP_0,
    APP_1,
};


/**
 * Loads the application identified by \a appid to the RAM.
 *
 * @param[in] appid  The identificator for the application to load.
 * 
 * @return  0 if the application was loaded correctly, an error code if the
 *          application failed to load.
 */
int application_load(enum APPLICATION_ID appid);


/**
 * Runs the application currently stored in the RAM.
 *
 * @todo  Will this method ever return if the application starts correctly?
 *
 * @return  An error code indicating the reason of the failure.
 */
int application_run();


/**
 * Adds the application at \a buffer to the slot identified by \a appid, giving
 * it the name \a name.
 *
 * @param[in] appid   The slot to which write the application to the persistent
 *                    storage.
 * @param[in] name    The human readable name to give to this application.
 * @param[in] buffer  The buffer from which to read the application to be
 *                    written.
 *
 * @return  0 if the operation completed successfully, an error code otherwise.
 */
int application_add(enum APPLICATION_ID appid, const char * name,
                    const char * buffer);


/**
 * Removes the application currently located at the slot \a appid from the
 * system.
 *
 * @param[in] appid  The slot in the persistent storage to free up.
 *
 * @return  0 if the operation completed successfully, an error code otherwise.
 */
int application_remove(enum APPLICATION_ID appid);


/**
 * Renames the application currently located at the slot \a appid, giving it the
 * name \a name.
 *
 * @param[in] appid  The slot in the persistent storage where the application to
 *                   rename is located.
 * @param[in] name   The new name to assign to this application.
 */
int application_rename(enum APPLICATION_ID appid, const char * name);
