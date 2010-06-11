#include <stdio.h>
#include <stdbool.h>

#include "timer.h"
#include "serial.h"

bool timeout_elapsed = false;

static void timeout_interrupt_handler() {
	uninstall_periodic_interrupt();
	timeout_elapsed = true;
}

int main (int argc, const char * argv[]) {
	install_periodic_interrupt(timeout_interrupt_handler, 20000);
	
	printf("Waiting...\n");
	
	while (!timeout_elapsed) {
		if (serial_buffered_chars_count()) {
			uninstall_periodic_interrupt();
			timeout_elapsed = true;
		}
	}
	
	if (serial_buffered_chars_count()) {
		/* Handle command */
	} else {
		/* Handle default action */
	}
	
	printf("Done!");
	
    return 0;
}