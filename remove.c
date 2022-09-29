#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "Itoa/itoa.h"

void remove(char *filename, int del_i) {
	int fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd < 0)
		return;
	for (int i = 0; i < size; i++) {
		if (i == del_i - 1)
			continue;
		char *tstr = itoa(ev[i].when, 10);
		write(fd, tstr, strlen(tstr));
		write(fd, "\t", 1);
		write(fd, ev[i].text, strlen(ev[i].text));
		write(fd, "\n", 1);
	}
	close(fd);
}
