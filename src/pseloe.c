#include <stdlib.h>
#include "Itoa/itoa.h"
#include "scalp.h"

/*
Print sorted enumerated list of events
*/
void pseloe(event *ev, int size) {
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
}
