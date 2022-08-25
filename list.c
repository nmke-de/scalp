#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "scalp.h"

void list(char *filename) {
	int size;
	event *ev = read_file(filename, NULL, &size);
	qsort(ev, size, sizeof(event), timecompare);
	for (int i = 0; i < size; i++) {
		// Print each item
		char *time_readable = ctime(&(ev[i].when));
		write(1, time_readable, strlen(time_readable) - 1);
		write(1, "\t", 1);
		write(1, ev[i].text, strlen(ev[i].text));
		write(1, "\n", 1);
	}
}
