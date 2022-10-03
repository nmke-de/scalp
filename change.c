#include <stdlib.h>
#include "Itoa/itoa.h"
#include "scalp.h"

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
	int change_i = atoi(buf) - 1;
	// Read in the new time
	read_time(buf, 21);
	// Read message from stdin
	int rl = prompt(msg, 512, "Message: ");
	// Check for overflow (and add a linefeed)
	if (rl == 512)
		msg[rl - 2] = '\n';
	// Write updates
	ev[change_i].when = atol(buf);
	strncpy(ev[change_i].text, msg, rl);
	rm(filename, ev, size, NULL, 0);
	// Update all running instances
	trigger_update(filename);
}
