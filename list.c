#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "scalp.h"

/*
routine to print a sorted list of all entries
*/
void list(char *filename) {
	// Read file
	int size;
	event *ev = read_file(filename, NULL, &size);
	// Sort entries
	qsort(ev, size, sizeof(event), timecompare);
	for (int i = 0; i < size; i++) {
		// Print each item
		char *time_readable = ctime(&(ev[i].when));
		// strlen - 1, since ctime adds an annoying newline at the end.
		write(1, time_readable, strlen(time_readable) - 1);
		write(1, "\t", 1);
		write(1, ev[i].text, strlen(ev[i].text));
		write(1, "\n", 1);
	}
}
