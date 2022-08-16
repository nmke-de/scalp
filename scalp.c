#include <unistd.h>
#include <signal.h>
// #include <stdlib.h>
#include "scalp.h"

static struct {
	event *ev;
	int size;
	char *filename;
} evlist = {
	NULL, 0, "foo"
};

static inline void sig_handle(int signum) {
	evlist.ev = read_file(evlist.filename, evlist.ev, &(evlist.size));
}

int main(int argc, char **argv) {
	evlist.filename = argc < 2 ? "foo" : argv[1];
	time_t t = time(NULL);
	evlist.ev = read_file(evlist.filename, NULL, &(evlist.size));
	signal(SIGUSR1, sig_handle);
	for(;; t = time(NULL)) {
		for(int i = 0; i < evlist.size; i++) if(t == evlist.ev[i].when) notify_send(evlist.ev[i].text);
		sleep(1);
	}
	// call to free is optimized away anyway.
	// free(ev);
	return 0;
}
