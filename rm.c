#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "Itoa/itoa.h"
#include "scalp.h"

/*
remove an entry from a file called filename. ev is expected to be the list of events, size the length of the list, and del_i the index (beginning with 0) of the entry to be removed.
*/
int rm(char *filename, event *ev, int size, int del_i) {
	int fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd < 0)
		return 1;
	for (int i = 0; i < size; i++) {
		if (i == del_i)
			continue;
		char *tstr = itoa(ev[i].when, 10);
		write(fd, tstr, strlen(tstr));
		write(fd, "\t", 1);
		write(fd, ev[i].text, strlen(ev[i].text));
		write(fd, "\n", 1);
	}
	close(fd);
	return 0;
}
