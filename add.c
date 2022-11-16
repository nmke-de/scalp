#include <fcntl.h>
#include "scalp.h"

/*
routine to add an entry to filename.
*/
void add(char *filename) {
	char msg[512];
	// Read time from stdin. Repeat if format is bad.
	char buf[21];
	read_time(buf, 21);
	// Read message from stdin
	int rl = prompt(msg, 512, "Message: ");
	// Check for overflow (and add a linefeed)
	if (rl == 512)
		msg[rl - 2] = '\n';
	// Write to file
	append(filename, buf, strlen(buf) - 1, msg, strlen(msg) - 1);
	// Update all running instances
	trigger_update(filename);
}
