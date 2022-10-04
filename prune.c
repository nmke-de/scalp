#include <fcntl.h>
#include <alloca.h>
#include "scalp.h"

// Support cproc alloca
#ifndef alloca
#define alloca __builtin_alloca
#endif

/*
removes all entries in filename which are older than now.
*/
void prune(char *filename) {
	int size = 0, ptr = 0;
	char buf[21];
	// Read file
	event *ev = read_file(filename, NULL, &size);
	// Get all outdated entries
	int *del_i = alloca(size * sizeof(int));
	time_t cut = time(NULL);
	for (int i = 0; i < size; i++)
		if (ev[i].when < cut)
			del_i[ptr++] = i;
	// Remove all entries
	rm(filename, ev, size, del_i, ptr);
	// Update all running instances
	trigger_update(filename);
}
