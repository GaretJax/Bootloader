/*
 * test_dispatcher.c
 *
 *  Created on: May 28, 2010
 *      Author: yves
 */
#include "dispatcher.h"

int main(int argc, const char *argv[]) {

	char* cmd = "Command p1 p2 p3 p4";
	int len1 = 5;
	int nbErrors = 0;
	char * tokens[MAX_ARGC];

	int nbTokens = command_parse(cmd, tokens);

	if (nbTokens != 5) {
		printf("Error: Number of tokens found: %d, %d expected!\n", nbTokens, 5);
		nbErrors++;
	} else {
		printf("command_parse with Command p1 p2 p3 p4: OK\n");
	}

	cmd = "Command";
	len1 = 1;

	nbTokens = command_parse(cmd, tokens);

	if (nbTokens != 1) {
		printf("Error: Number of tokens found: %d, %d expected!\n", nbTokens, 1);
		nbErrors++;
	} else {
		printf("command_parse with Command: OK\n");
	}

	cmd = "Command p1";
	len1 = 2;

	nbTokens = command_parse(cmd, tokens);

	if (nbTokens != 2) {
		printf("Error: Number of tokens found: %d, %d expected!\n", nbTokens, 2);
		nbErrors++;
	} else {
		printf("command_parse with Command p1: OK\n");
	}

	cmd = "";
	len1 = 0;

	nbTokens = command_parse(cmd, tokens);

	if (nbTokens != -1) {
		printf("Error: Number of tokens found: %d, %d expected!\n", nbTokens,
				-1);
		nbErrors++;
	} else {
		printf("command_parse with empty string: OK\n");
	}

	if (nbErrors > 1) {
		printf("\nTest failed with %d errors", nbErrors);
	} else {
		printf("\nTest passed successfully");
	}

}

