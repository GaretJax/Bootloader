#include <dispatcher.h>
#include <registry.h>

int command_parse(const char * cmd, char * args[]) {
    char * cmdCopy = strdup(cmd);    // Duplicates the cmd string because strtok is gonna modify it
    int i = 0;
    char * delim = " ";
    args[i] = strtok(cmdCopy, delim);    // Copy the first token of string into args[0]
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, delim);
    }
    if (i == 0) {    // if we didnt find any tokens
        return -1;
    } else {
        return i;
    }
}

int command_dispatch(int argc, char * argv[]) {
    if (argv[0] == 0) {
        return -1;
    }
    char* cmdName = argv[0];
    Command cmd = command_registry_get(cmdName);
    int error = cmd(argc, argv);
    return error;
}

int command_parse_and_dispatch(const char * cmd) {
    char* args[MAX_ARGC];
    int tokens = command_parse(cmd, args);
    if (tokens == -1) return -1;
    int dispatchError = command_dispatch(tokens, args);
    return dispatchError;
}
