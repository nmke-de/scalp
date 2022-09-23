#include <unistd.h>
#include "scalp.h"

/*
routine to update all running instances of scalp
*/
void trigger_update(char *filename) {
	char *args[] = {"killall", "-s", "USR1", "scalp", NULL};
	if (fork() == 0)
		execvp("killall", args);
}
