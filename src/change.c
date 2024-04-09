#include <stdlib.h>
#include "Itoa/itoa.h"
#include "scalp.h"

// TODO do it differently.

/*
routine to change an existing entry. This is not final - I am not happy with the interface.
*/
void change(char *filename) {
	int size = 0;
	char buf[21];
	char msg[512];
	// Read file
	event *ev = read_file(filename, NULL, &size);
	// Print sorted enumerated list of events
	pseloe(ev, size);
	// User input
	prompt(buf, 21, "Which event do you want to change? ");
	int i[1];
	i[0] = atoi(buf) - 1;
	// Read message from stdin
	int rl = prompt(msg, 512, "Message: ");
	// Check for overflow (and add a linefeed)
	if (rl == 512)
		msg[rl - 2] = '\n';
	// Write updates
	rm(filename, ev, size, i, 1);
	char *time = itoa(ev[*i].when, 10);
	append(filename, time, strlen(time), msg, strlen(msg) - 1);
	// Update all running instances
	trigger_update(filename);
}
