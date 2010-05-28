#include "registry.h"
#include <stdio.h>

int func1(int argc, const char * argv[]) {
	printf("func1");
	return 0;
}

int func2(int argc, const char * argv[]) {
	printf("func2");
	return 0;
}

int func3(int argc, const char * argv[]) {
	printf("func3");
	return 0;
}

int func4(int argc, const char * argv[]) {
	printf("func4");
	return 0;
}

int main(int argc, const char *argv[]) {
	int numArgs = 4;
	int errorCountTest1 = 0;
	int errorCountTest2 = 0;


	char* args[numArgs];
	args[0] = "arg1";
	args[1] = "arg2";
	args[2] = "arg3";
	args[3] = "arg4";

	char* funcIds[numArgs];
	funcIds[0] = "func1";
	funcIds[1] = "func2";
	funcIds[2] = "func3";
	funcIds[3] = "func4";

	Command funcs[numArgs];
	funcs[0] = func1;
	funcs[1] = func2;
	funcs[2] = func3;
	funcs[3] = func4;

	Command cmd;

	// Test 1 --------------------------------------------------------
	// Do a get on an empty command registry
	printf("Test 1\n");
	char* commandId = funcIds[0];
	cmd = command_registry_get(funcIds[0]);
	if (cmd == 0) {
		printf("Get of empty command list: OK\n");
	} else {
		printf("Error: Get of empty command list returned %d, should be 0\n");
		errorCountTest1++;
	}

	// Insert one command
	cmd = funcs[0];
	int response = command_registry_register(funcIds[0], cmd);
	if (response == 0) {
		printf("Insert of %s OK\n", funcIds[0]);
	} else {
		printf("Error: Insert of %s failed\n", funcIds[0]);
		errorCountTest1++;
	}

	// Get the inserted command
	cmd = command_registry_get(funcIds[0]);
	if (cmd == &func1) {
		printf("Get of %s OK\n", funcIds[0]);
	} else {
		printf("Error: Get of %s failed, cmd at %d and func1 at %d\n",
				funcIds[0], cmd, &func1);
		errorCountTest1++;
	}

	// Remove inserted command
	response = command_registry_unregister(funcIds[0]);
	if (response == 0) {
		// Try to get removed command to be sure it was removed
		cmd = command_registry_get(funcIds[0]);
		if (cmd == 0) {
			printf("Remove of %s OK\n", funcIds[0]);
		}
	} else if (response < 0) {
		printf("Error: Could not unregister command %s", funcIds[0]);
		errorCountTest1++;
	} else if (response > 0) {
		printf("Error: Command %s could not be found. Can not unregister",
				funcIds[0]);
		errorCountTest1++;
	}


	// Test 2 --------------------------------------------------------
	printf("\n\nTest 2:\n");
	int i;

	// Add all commands
	for (i = 0; i < numArgs; i++) {
		response = command_registry_register(funcIds[i], funcs[i]);
		if (response == 0) {
			printf("Insert of %s OK\n", funcIds[i]);
		} else {
			printf("Error: Insert of %s failed\n", funcIds[i]);
			errorCountTest2++;
		}
	}

	// Get all commands
	for (i = 0; i < numArgs; i++) {
		cmd = command_registry_get(funcIds[i]);
		if (cmd == funcs[i]) {
			printf("Get of %s OK\n", funcIds[i]);
		} else {
			printf("Error: Get of %s failed, cmd at %d and func1 at %d\n",
					funcIds[i], cmd, funcs[i]);
			errorCountTest2++;
		}
	}

	// Remove last inserted command
	response = command_registry_unregister(funcIds[numArgs - 1]);
	if (response == 0) {
		// Try to get removed command to be sure it was removed
		cmd = command_registry_get(funcIds[numArgs - 1]);
		if (cmd == 0) {
			printf("Remove of %s OK\n", funcIds[numArgs - 1]);
		}
	} else if (response < 0) {
		printf("Error: Could not unregister command %s", funcIds[numArgs - 1]);
		errorCountTest2++;
	} else if (response > 0) {
		printf("Error: Command %s could not be found. Can not unregister",
				funcIds[numArgs - 1]);
		errorCountTest2++;
	}

	printf("\nTest 1 finished with %d errors\n", errorCountTest1);
	printf("Test 2 finished with %d errors\n", errorCountTest2);

	return 0;
}


