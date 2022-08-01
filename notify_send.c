#include <unistd.h>
#include "scalp.h"

void notify_send(char *msg) {
	char *args[4] = {"notify-send", "BINGO!", msg, NULL};
	if(fork() == 0) execvp("notify-send", args);
}
