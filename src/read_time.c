#include <fcntl.h>
#include "scalp.h"

/*
prompts user to give a date time.
*/
int read_time(char *buf, int max_bufsize) {
	char tmp_time[64];
	int pfd[2];
	int rl;
	// This is necessary to ensure that the loop actually loops if the input format is bad.
	*buf = 0;
	do {
		// Get user input for time
		print("Time: ");
		rl = input(tmp_time, 64);
		tmp_time[rl - 1] = 0;
		// Spawn child process and open pipe
		if (pipe(pfd) < 0)
			return 1;
		pid_t pid = fork();
		if (pid < 0) {
			close(pfd[0]);
			close(pfd[1]);
			return 1;
		} else if (pid == 0) {
			char *argv[] = {"date", "+%s", "-d", tmp_time, 0};
			close(pfd[0]);
			close(1);
			dup2(pfd[1], 1);
			close(pfd[1]);
			execvp("date", argv);
			// Only executed if something is wrong with `date`.
			write(1, "W", 1);
			return 1;
		}
		close(pfd[1]);
		fcntl(pfd[0], F_SETFD, FD_CLOEXEC);
		// Read input from *pfd
		int i = 0;
		read(*pfd, buf, max_bufsize);
		close(*pfd);
		if (*buf == 'W') {
			// Only executed if something is wrong with `date`.
			print("scalp received an error. Are you sure that the `date` utility is properly installed?\n");
			return 1;
		}
	} while (*buf == 0);
	return 0;
}
