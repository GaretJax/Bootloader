/**
 * @file commands/registry.h
 *
 * A registry which allows to add, remove and get pointers to Command like
 * functions using a given name as identifier. This data structure is mainly
 * used by the dispatcher to store all the known commands and retrieve them by
 * name.
 */


#pragma once


/**
 * The interface which all functions used as commands have to implement.
 * The interface is similar to the required prototype for the \c main method; it
 * takes an \a argc argument indicating the number of arguments and an \c argv
 * argument which points to an array of strings, already splitted by the command
 * parser. The function must return 0 if completed successfully or a custom
 * positive error code if it fails.
 */
typedef int (* Command) (int argc, const char * argv[]);


/**
 * Adds a given command to the commands registry using the given name.
 * If a command was already registered with the same name, it is overwritten.
 *
 * @param[in] name  The string indicating the name to use to identify the
 *                  command.
 * @param[in] cmd   The pointer to the command function to register under the
 *                  given name.
 *
 * @return  0 if the value was read correctly, a negative error code otherwise.
 */
int command_registry_register(const char * name, Command cmd);


/**
 * Removes the command identified by the given name from the command registry.
 *
 * @param[in] name  The string indicating the name of the command to remove.
 *
 * @return  0 if the command was removed correctly, 1 if it was not found and a
 *          negative error code if an error occurred.
 */
int command_registry_unregister(const char * name);


/**
 * Retrieves and returns the command identified by the given name.
 *
 * @param[in] name  The string indicating the name of the command to retrieve.
 *
 * @return  The command if a value existed for the key name, NULL otherwise.
 */
Command command_registry_get(const char * name);
