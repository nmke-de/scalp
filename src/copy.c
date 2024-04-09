#include <stdlib.h>
#include "Itoa/itoa.h"
#include "scalp.h"

/*
routine to copy an existing appointment.
*/
void copy(char *filename) {
	int size = 0;
	char buf[21];
	// Read file
	event *ev = read_file(filename, NULL, &size);
	// Print sorted enumerated list of events
	pseloe(ev, size);
	// User input
	prompt(buf, 21, "Which event do you want to copy? ");
	int i[1];
	i[0] = atoi(buf) - 1;
	// Read in the new time
	read_time(buf, 21);
	append(filename, buf, strlen(buf) - 1, ev[*i].text, strlen(ev[*i].text));
	// Update all running instances
	trigger_update(filename);
}
