#include <unistd.h>
#include "scalp.h"

void notify_send(char *title, char *msg) {
	char *args[] = {"notify-send", title, msg, NULL};
	if (fork() == 0)
		execvp("notify-send", args);
}
