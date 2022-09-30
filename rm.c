#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "Itoa/itoa.h"
#include "scalp.h"

/*
remove an entry from a file called filename. ev is expected to be the list of events, size the length of the list, and del_i a list of indices (beginning with 0) of the entries to be removed, with size del_i_size
*/
int rm(char *filename, event *ev, int size, int *del_i, int del_i_size) {
	int fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd < 0)
		return 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < del_i_size; j++) {
			if (i == del_i[j])
				goto next;
		}
		char *tstr = itoa(ev[i].when, 10);
		write(fd, tstr, strlen(tstr));
		write(fd, "\t", 1);
		write(fd, ev[i].text, strlen(ev[i].text));
		write(fd, "\n", 1);
	next:
	}
	close(fd);
	return 0;
}
