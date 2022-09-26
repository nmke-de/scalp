#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "scalp.h"

// Macros to make code more managable
#define print(str) write(0, (str), strlen((str)))
#define input(var, limit) read(1, (var), (limit))

/*
routine to add an entry to filename.
*/
void add(char *filename) {
	char msg[512];
	char tmp_time[64];
	// Read time from stdin. Repeat if format is bad.
	char buf[21];
	int pfd[2];
	do {
		// Get user input for time
		print("Time: ");
		int rl = input(tmp_time, 64);
		tmp_time[rl - 1] = 0;
		// Spawn child process and open pipe
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
		} while (buf[i] != -1);
		close(*pfd);
	} while (*buf == 0);
	// Read message from stdin
	print("Message: ");
	int rl = input(msg, 512);
	// Check for overflow
	if (rl == 512) {
		msg[rl - 1] = 0;
		msg[rl - 2] = '\n';
		// Remove characters that are still in the input buffer
		char junk[16];
		do {
			rl = input(junk, 16);
		} while (junk[rl - 1] != '\n');
	}
	// Write to file
	int fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
		return;
	write(fd, buf, strlen(buf) - 1);
	write(fd, "\t", 1);
	write(fd, msg, strlen(msg));
	close(fd);
	// Update all running instances
	trigger_update(filename);
}
