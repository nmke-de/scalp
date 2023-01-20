#include <stdlib.h>
#include "Itoa/itoa.h"
#include "scalp.h"

/*
routine to repeat an existing entry in regular intervals (daily, weekly, monthly, yearly)
*/
void repeat(char *filename) {
	int size = 0;
	char buf[21];
	// Read file
	event *ev = read_file(filename, NULL, &size);
	// Print sorted enumerated list of events
	pseloe(ev, size);
	// User input
	prompt(buf, 21, "Which event do you want to repeat? ");
	int i = atoi(buf) - 1;
	prompt(buf, 21, "How often? (Y)early, (M)onthly, (W)eekly, (D)aily ");
	long interval;
	switch (*buf) {
		case 'Y':
		case 'y':
			// TODO fix irregular years
			interval = 3600 * 24 * 365;
			break;
		case 'M':
		case 'm':
			// TODO fix irregular months
			interval = 3600 * 24 * 30;
			break;
		case 'W':
		case 'w':
			interval = 3600 * 24 * 7;
			break;
		case 'D':
		case 'd':
			interval = 3600 * 24;
			break;
		default:
			free(ev);
			return;
	}
	write(0, "Until? ", 7);
	read_time(buf, 21);
	time_t stop = atoi(buf);
	// Add new events
	for (time_t t = ev[i].when + interval; t <= stop; t += interval)
		append(filename, itoa(t, 10), strlen(itoa(t, 10)), ev[i].text, strlen(ev[i].text));
	// Update all running instances
	trigger_update(filename);
}
