#include <unistd.h>
#include "scalp.h"

void add(char *filename) {
	char *args[] = {"sh", "./scalp-add.sh", filename, "interactive", NULL};
	if (fork() == 0)
		execvp("sh", args);
}
