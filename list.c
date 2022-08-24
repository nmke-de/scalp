#include "scalp.h"

void list(char *filename) {
	int size;
	event *ev = read_file(filename, NULL, &size);
	for (int i = 0; i < size; i++) {
		// Print each item
	}
}