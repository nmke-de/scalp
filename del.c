#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "Itoa/itoa.h"
#include "scalp.h"

// Macros to make code more managable
#define print(str) write(0, (str), strlen((str)))
#define input(var, limit) read(1, (var), (limit))

/*
routine to remove an entry from filename.
*/
void del(char *filename) {
	int size = 0;
	char buf[21];
	// Read file
	event *ev = read_file(filename, NULL, &size);
	// Sort entries
	qsort(ev, size, sizeof(event), timecompare);
	// Print a list of all entries to output
	for (int i = 0; i < size; i++) {
		char *tmp = itoa(i + 1, 10);
		print(tmp);
		print("\t");
		tmp = ctime(&(ev[i].when));
		write(0, tmp, strlen(tmp) - 1);
		print("\t");
		print(ev[i].text);
		print("\n");
	}
	// User input
	print("Which event do you want to delete? ");
	int rl = input(buf, 21);
	// Check for overflow
	if (rl == 21) {
		buf[rl - 1] = 0;
		// Remove characters that are still in the input buffer
		char junk[16];
		do {
			rl = input(junk, 16);
		} while (junk[rl - 1] != '\n');
	}
	// Index of item that is to be deleted (starting with 1).
	int del_i[1];
	del_i[0] = atoi(buf) - 1;
	// Write to file
	rm(filename, ev, size, del_i, 1);
	// Update all running instances
	trigger_update(filename);
}
