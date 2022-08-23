#include <unistd.h>
#include <signal.h>
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

void scalpd(char *filename) {
	time_t t = time(NULL);
	evlist.filename = filename;
	evlist.ev = read_file(evlist.filename, NULL, &(evlist.size));
	signal(SIGUSR1, sig_handle);
	for(;; t = time(NULL)) {
		for(int i = 0; i < evlist.size; i++) if(t == evlist.ev[i].when) notify_send(evlist.ev[i].text);
		sleep(1);
	}
}
