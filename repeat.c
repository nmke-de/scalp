#include <stdlib.h>
#include "Itoa/itoa.h"
#include "scalp.h"

#define isleap(y) (!(y % 400) || (!!(y % 100) && !(y % 4)))

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
	char mode = *buf;
	switch (*buf) {
		case 'Y':
		case 'y':
			interval = 3600 * 24 * 365;
			break;
		case 'M':
		case 'm':
			interval = 3600 * 24 * 28;
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
	struct tm *t_broken_down = (struct tm *)0;
	for (time_t t = ev[i].when + interval; t <= stop; t += interval) {
		t_broken_down = gmtime(&t);
		if ((mode == 'Y' || mode == 'y') && isleap(t_broken_down->tm_year))
			t += (3600 * 24);
		else if (mode == 'M' || mode == 'm')
			switch (t_broken_down->tm_mon) {
				case 0:
				case 2:
				case 4:
				case 6:
				case 7:
				case 9:
				case 11:
					t += (3600 * 72);
					break;
				case 1:
					if (isleap(t_broken_down->tm_year))
						t += (3600 * 24);
					break;
				default:
					t += (3600 * 48);
			}
		append(filename, itoa(t, 10), strlen(itoa(t, 10)), ev[i].text, strlen(ev[i].text));
	}
	// Update all running instances
	trigger_update(filename);
}
