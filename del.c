#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "scalp.h"

#define print(str) write(0, (str), strlen((str)))
#define input(var, limit) read(1, (var), (limit))

void del(char *filename) {
	int size = 0;
	char buf[21];
	event *ev = read_file(filename, NULL, &size);
	qsort(ev, size, sizeof(event), timecompare);
	for (int i = 0; i < size; i++) {
		print(ctime(ev[i].when));
		print("\t");
		print(ev[i].text);
		print("\n");
	}
	print("Which event? ");
	input(buf, 21);
	// Index of item that is to be deleted.
	int del_i = atoi(buf);
	int fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd < 0)
		return;
	for(int i = 0; i < size; i++) {
		if (i == del_i - 1)
			continue;
		//write(fd, )
	}
	close(fd);
	trigger_update(filename);
}
