#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "scalp.h"

void add(char *filename) {
	char *msg = "TESTIFICATE";
	char *tmp_time = "today 4pm";
	char buf[21];
	// Spawn child process and open pipe
	int pfd[2];
	if (pipe(pfd) < 0)
		return;
	pid_t pid = fork();
	if (pid < 0) {
		close(pfd[0]);
		close(pfd[1]);
		return;
	} else if (pid == 0) {
		char *argv[] = {"date", "+%s", "-d", tmp_time, 0};
		close(pfd[0]);
		close(1);
		dup2(pfd[1], 1);
		close(pfd[1]);
		execvp("date", argv);
	}
	close(pfd[1]);
	fcntl(pfd[0], F_SETFD, FD_CLOEXEC);
	// Read input from *pfd
	int i = 0;
	do {
		read(*pfd, buf + i, 1);
		++i;
	} while (buf[i] != 10);
	close(*pfd);
	// Write to file
	int fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
		return;
	write(fd, buf, strlen(buf) - 1);
	write(fd, "\t", 1);
	write(fd, msg, strlen(msg));
	write(fd, "\n", 1);
	close(fd);
	// Update all running instances
	trigger_update(filename);
}
