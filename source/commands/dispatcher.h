/**
 * @file commands/dispatcher.h
 *
 * This files contains various utilities which operate on the commands registry
 * to parse a shell like command string and to call the command with the
 * retrieved arguments.
 */


#pragma once
#include "registry.h"


/**
 * The maximum number of tokens which an array should be able to contain.
 */
#define MAX_ARGC 100


/**
 * Parses a command string and populates an array with the obtained tokens.
 *
 * @pre  \a args is an array of size \c MAX_ARGC
 *
 * @param[in]  cmd   The string containing the command to parse.
 * @param[out] args  The array which will be populated with the tokens obtained
 *                   by parsing the \a cmd argument.
 *
 * @return  The number of found tokens (the count of items in \a args) or a
 *          negative error code if the function fails.
 */
int command_parse(const char * cmd, char * args[]);


/**
 * Takes a list of tokens and its count and executes the registered command.
 * This function takes the first ite in \a argv and retrieves the command
 * from the registry using this string.
 *
 * @param[in] argc  The number of tokens contained in \a argv.
 * @param[in] argv  The tokens as returned by the \c command_parse function.
 *
 * @return  The status code of the executed command (either 0 or a positive
 *          error code if the command execution failed) or a negative error code
 *          if it was not possible to call the command.
 */
int command_dispatch(int argc, const char * argv[]);


/**
 * Shortcut function to directly parse and dispatch a command in one step.
 * This function calls \c command_parse and passes its results to
 * \c command_dispatch
 *
 * @param[in] cmd  The string containing the command to parse.
 *
 * @return  The value returned by the \c command_dispatch function call.
 */
int command_parse_and_dispatch(const char * cmd);
