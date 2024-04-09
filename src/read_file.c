#include <stdio.h>
#include <stdlib.h>
#include "scalp.h"

/*
Read file to an array of events of size *size. TODO use unistd.h instead of stdio.h
*/
event *read_file(const char *filename, event *res, int *size) {
	// Open file
	FILE *f = fopen(filename, "r");
	if (!f) {
		fputs("error: scalp: filename missing.\n", stderr);
		exit(1);
	}
	char buf[MAX_EVENT_TEXT];
	// Count lines
	*size = 0;
	for (char c = fgetc(f); c != EOF; c = fgetc(f))
		if (c == '\n')
			(*size)++;
	rewind(f);
	// Allocate memory
	res = realloc(res, *size * sizeof(event));
	// For each line, ...
	for (int i = 0; i < *size; i++) {
		// Read the time as seconds since UNIX Epoch...
		{
			int j = 0;
			for (; j < MAX_EVENT_TEXT && (buf[j] = fgetc(f)) >= '0' && buf[j] <= '9'; j++)
				;
			buf[j] = 0;
		}
		res[i].when = atol(buf);
		// And read the message. TODO ignore any characters after 512 characters.
		{
			int j = 0;
			for (; j < MAX_EVENT_TEXT && (buf[j] = fgetc(f)) != '\n' && buf[j] != EOF; j++)
				;
			for (; j < MAX_EVENT_TEXT; j++)
				buf[j] = 0;
			strncpy(res[i].text, buf, j);
		}
	}
	// Close file and return
	fclose(f);
	return res;
}
