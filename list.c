#include <stdio.h>
#include <stdlib.h>
#include "scalp.h"

void list(char *filename) {
	int size;
	event *ev = read_file(filename, NULL, &size);
	qsort(ev, size, sizeof(event), timecompare);
	for (int i = 0; i < size; i++) {
		// Print each item
		fputs(ctime(&(ev[i].when)), stdout);
		fputc('\t', stdout);
		fputs(ev[i].text, stdout);
		fputc('\n', stdout);
	}
}