#include "scalp.h"

/*
On SIGUSR1, reread file
*/
void sighandle(int signum) {
	evlist.ev = read_file(evlist.filename, evlist.ev, &(evlist.size));
}