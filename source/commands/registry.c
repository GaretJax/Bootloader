#include <string.h>

struct CommandItem {
    Command cmd;
    char* name[MAX_NAME_LENGTH];
    struct CommandItem* next;
};

struct CommandItem last = 0;
struct CommandItem first = 0;


int command_registry_register(const char * name, Command cmd) {
    struct CommandItem* nextCmd = malloc (sizeof(struct CommandItem));
    nextCmd->cmd = cmd;
    strncpy (nextCmd->name, name, MAX_NAME_LENGTH);
    nextCmd->next = 0;

    if (last == 0) {
        last = nextCmd;
        first = nextCmd;
    } else {
        last->next = nextCmd;
        last = nextCmd;
    }
    
    return 0;    //TODO: verify if insert worked correctly
}


int command_registry_unregister(const char * name) {
    struct CommandItem* cmdItr = first;

    if (first == 0) {
        return 1;    // No command found
    }

    if (cmdItr->next == 0) {    // If there is only one cmd in CommandItem we remove it
        cmdItr->cmd = 0;
        cmdItr->name = 0;
        first = 0;
        last = 0;
        free(cmdItr);
        return 0;    //TODO: verify if insert worked correctly
    }

    if (strcmp(cmdItr->name, name) == 0) {    // If we remove first element
        first = cmdItr->next;
        free(cmdItr);
    }

    while (strcmp(cmdItr->next->name, name) != 0) {
        if (cmdItr->next == 0) {
            return 1;    // No command found
        }
        cmdItr = cmdItr->next;
    }

    if (cmdItr->next == last) {
        last = cmdItr;
        cmdItr->next = 0;
        free(cmdItr->next);
        return 0;    //TODO: verify if insert worked correctly
    }

    cmdItr->next = cmdItr->next->next;
    free(cmdItr->next);
    return 0;    //TODO: verify if insert worked correctly
}

Command command_registry_get(const char * name) {
    struct CommandItem* cmdItr = first;
    while (strcmp(cmdItr->name, name) != 0) {
        if (cmdItr->next == 0) {
            return NULL;
        }
        cmdItr = cmdItr->next;
    }
    return cmdItr->cmd;
}
