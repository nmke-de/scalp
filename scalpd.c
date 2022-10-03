#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "scalp.h"

// Packaged globals. Needed to be accessible for borth scalpd and the signal handlers.
static struct {
	event *ev;
	int size;
	char *filename;
} evlist = {
	NULL, 0, "foo"
};

/*
Signal handler for USR1, which updates the memory of the running instance of scalp.
*/
static inline void sig_handle(int signum) {
	evlist.ev = read_file(evlist.filename, evlist.ev, &(evlist.size));
}

/*
Signal handler for USR2. Used for debugging. If you are a developer, feel free to change.

The log macro is just a little bit convenience.
*/
#define log(str) write(2, (str), strlen((str)))
static inline void sig2_handle(int signum) {
	for (int i = 0; i < evlist.size; i++) {
		log(evlist.ev[i].text);
		log("\n");
	}
}

/*
routine to run the scalp daemon. Default mode, if no subcommand is given.
*/
void scalpd(char *filename) {
	time_t t = time(NULL);
	// Read file
	evlist.filename = filename;
	evlist.ev = read_file(evlist.filename, NULL, &(evlist.size));
	// Set up signal handlers
	signal(SIGUSR1, sig_handle);
	signal(SIGUSR2, sig2_handle);
	// Main loop
	for (;; t = time(NULL)) {
		// Check for each entry whether it is time to notify the user.
		for (int i = 0; i < evlist.size; i++) {
			if (t == evlist.ev[i].when)
				notify_send("NOW!", evlist.ev[i].text);
			else if (t == evlist.ev[i].when - 600)
				notify_send("In ten minutes!", evlist.ev[i].text);
			else if (t == evlist.ev[i].when - 3600)
				notify_send("In an hour!", evlist.ev[i].text);
			else if (t == evlist.ev[i].when - 86400)
				notify_send("Tomorrow!", evlist.ev[i].text);
		}
		// Run the loop each second. This is sufficient in my experience.
		sleep(1);
	}
}
