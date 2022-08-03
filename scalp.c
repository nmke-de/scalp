#include <unistd.h>
#include <stdlib.h>
#include "scalp.h"

int main(int argc, char **argv) {
	char *filename = argc < 2 ? "foo" : argv[1];
	time_t t = time(NULL);
	int size;
	event *ev = read_file(filename, &size);
	for(;; t = time(NULL)) {
		for(int i = 0; i < size; i++) if(t == ev[i].when) notify_send(ev[i].text);
		sleep(1);
	}
	free(ev);
	return 0;
}
