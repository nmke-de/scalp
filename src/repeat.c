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
	long interval = 0;
	char mode = *buf;
	switch (mode) {
		case 'Y':
		case 'y':
			// Solved differently
			break;
		case 'M':
		case 'm':
			// Solved differently
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
		// Increment t for year mode and month mode
		t_broken_down = gmtime(&t);
		t_broken_down->tm_isdst = -1;
		if ((mode == 'Y' || mode == 'y')) {
			t_broken_down->tm_year++;
			// Adding 3600 (1 hour) gives the correct time. I don't know the exact reason for this.
			t = mktime(t_broken_down) + 3600;
		} else if (mode == 'M' || mode == 'm') {
			if (t_broken_down->tm_mon < 11) {
				t_broken_down->tm_mon++;
				t = mktime(t_broken_down) + 3600;
			} else {
				t_broken_down->tm_year++;
				t_broken_down->tm_mon = 0;
				t = mktime(t_broken_down) + 3600;
			}
			// Temporary solution to the DST problem. Not exactly correct, but I can't be bothered
			// with implementing a correct DST solution for scalp at 10pm. I did'nt like DST before,
			// but now this is becoming a personal vendetta against DST.
			if (t_broken_down->tm_mon > 3 && t_broken_down->tm_mon < 11)
				t += 3600;
		}
		// Test for break condition for year mode and month mode
		if (t > stop)
			break;
		append(filename, itoa(t, 10), strlen(itoa(t, 10)), ev[i].text, strlen(ev[i].text));
	}
	// Update all running instances
	trigger_update(filename);
}
