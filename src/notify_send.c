#include "scalp.h"
#include "../config.h"

/*
routine to notify the user.
*/
void notify_send(char *title, char *msg) {
	char *args[] = notify_command;
	if (fork() == 0)
		execvp(*args, args);
}
