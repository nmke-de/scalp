#include <fcntl.h>
#include "scalp.h"

/*
append appends a new entry to the file filename with the time time (in Unix epoch format) and the message msg. This function does not check whether the message is too long.
*/
int append(char *filename, char *time, int len1, char *msg, int len2) {
	int fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
		return 1;
	write(fd, time, len1);
	write(fd, "\t", 1);
	write(fd, msg, len2);
	write(fd, "\n", 1);
	close(fd);
	return 0;
}
