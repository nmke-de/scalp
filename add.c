#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "scalp.h"

void add(char *filename) {
	char *msg = "TESTIFICATE";
	char *tmp_time = "today 4pm";
	char buf[523]; // 10 for time, one separator, 512 for message
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
	for (; i < 10; i++)
		read(*pfd, buf + i, 1);
	buf[++i] = '\t';
	strncpy(buf + (++i), msg, strlen(msg));
	close(*pfd);
	//Write to file
	int fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
		return;
	write(fd, buf, strlen(msg));
	close(fd);
	/*time_t t = time(NULL);
	char msg[512], tstr[64];
	// print("Time: ");
	// input(tstr, 16);
	struct tm *t_struct = localtime(&t);
	strcat(tstr, "date +%s -d '");
	strcat(tstr, inputstring);
	strcat(tstr, "'");
	FILE *f = popen(tstr, "r");
	char *buf[523]; // 10 for time, one separator, 512 for message
	int i = 0;
	for(; i < 10; i++)
		buf[i] = fgetc(f);
	buf[i] = '\t';
	fclose(f);

	int fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return 1;
	close(fd);*/
}
