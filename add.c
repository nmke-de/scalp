#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "scalp.h"

// Macros to make code more managable
#define print(str) write(0, (str), strlen((str)))
#define input(var, limit) read(1, (var), (limit))

/*
routine to add an entry to filename.
*/
void add(char *filename) {
	char msg[512];
	char tmp_time[64];
	// Read time from stdin. Repeat if format is bad.
	char buf[21];
	read_time(buf, 21);
	// Read message from stdin
	print("Message: ");
	int rl = input(msg, 512);
	// Check for overflow
	if (rl == 512) {
		msg[rl - 1] = 0;
		msg[rl - 2] = '\n';
		// Remove characters that are still in the input buffer
		char junk[16];
		do {
			rl = input(junk, 16);
		} while (junk[rl - 1] != '\n');
	}
	// Write to file
	append(filename, buf, strlen(buf) - 1, msg, strlen(msg) - 1);
	// Update all running instances
	trigger_update(filename);
}
