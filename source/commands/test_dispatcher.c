/**
 * Testfile for dispatcher.c
 *
 * @author Yves Peissard
 */
#include "dispatcher.h"
#include <stdio.h>

int command1(int argc, const char * argv[]) {
	return 1;
}

int command2(int argc, const char * argv[]) {
	return 2;
}

int command3(int argc, const char * argv[]) {
	return 3;
}

int command4(int argc, const char * argv[]) {
	return 4;
}

int main2(int argc, const char *argv[]) {

	char* cmd = "command p1 p2 p3 p4";
	int len1 = 5;
	int nbErrorsParse = 0;
	int nbErrorsDispatch = 0;
	int nbErrorsParseDispatch = 0;
	char * tokens[MAX_ARGC];

	int nbTokens = command_parse(cmd, tokens);

	/* Test command_parse 1 */
	if (nbTokens != 5) {
		printf(
				"Error at command_parse: Number of tokens found: %d, %d expected!\n",
				nbTokens, 5);
		nbErrorsParse++;
	} else if (strcmp("command", tokens[0]) != 0) {
		printf(
				"Error at command_parse: tokens[0] = %s, should be \"command\"!",
				tokens[0]);
		nbErrorsParse++;
	} else {
		printf("command_parse with command p1 p2 p3 p4: OK\n");
	}

	/* Test command_parse 2 */
	cmd = "command";
	len1 = 1;
	nbTokens = command_parse(cmd, tokens);

	if (nbTokens != 1) {
		printf(
				"Error at command_parse: Number of tokens found: %d, %d expected!\n",
				nbTokens, 1);
		nbErrorsParse++;
	} else {
		printf("command_parse with command: OK\n");
	}

	/* Test command_parse 3 */
	cmd = "command p1";
	len1 = 2;
	nbTokens = command_parse(cmd, tokens);

	if (nbTokens != 2) {
		printf(
				"Error at command_parse: Number of tokens found: %d, %d expected!\n",
				nbTokens, 2);
		nbErrorsParse++;
	} else {
		printf("command_parse with command p1: OK\n");
	}

	/* Test command_parse 4 */
	cmd = "";
	len1 = 0;
	nbTokens = command_parse(cmd, tokens);

	if (nbTokens != -1) {
		printf("Error at command_parse: Number of tokens found: %d, %d expected!\n",
				nbTokens, -1);
		nbErrorsParse++;
	} else {
		printf("command_parse with empty string: OK\n");
	}

	/* Test command_dispatch 1 */
	int result = 0;
	cmd = "command1 p1 p2 p3 p4";
	argc = 5;

	command_registry_register("command1", command1);
	command_parse(cmd, (char **) argv);
	result = command_dispatch(5, argv);

	if (result != 1) {
		printf("Error at command_dispatch: Return value should be 1, %d received", result);
		nbErrorsDispatch++;
	} else if (result == -1) {
		printf("Error at command_dispatch: Command command1 not found");
	}

	/* Test command_parse_and_dispatch 1 */
	cmd = "command2 p1 p2 p3 p4";
	command_registry_register("command2", command2);
	result = command_parse_and_dispatch(cmd);

	if (result != 2) {
		printf("Error at command_parse_and_dispatch: Return value should be 1, %d received", result);
		nbErrorsParseDispatch++;
	} else if (result == -1) {
		printf("Error at command_parse_and_dispatch: Command command2 not found");
	}

	if (nbErrorsParse > 0) {
		printf("\n\nTest command_parse failed with %d errors", nbErrorsParse);
	} else {
		printf("\n\nTest command_parse passed successfully");
	}

	if (nbErrorsDispatch > 0) {
		printf("\n\nTest command_dispatch failed with %d errors", nbErrorsDispatch);
	} else {
		printf("\n\nTest command_dispatch passed successfully");
	}

	if (nbErrorsParseDispatch > 0) {
		printf("\n\nTest command_dispatch failed with %d errors", nbErrorsParseDispatch);
	} else {
		printf("\n\nTest command_parse_and_dispatch passed successfully");
	}

	return 0;
}

