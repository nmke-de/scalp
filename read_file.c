#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scalp.h"

#define readnum (f, buf) ;{int j = 0; for (; j < MAX_EVENT_TEXT && (buf[j] = fgetc(f)) >= '0' && buf[j] <= '9'; j++) {} buf[j] = 0;}

event *read_file (const char *filename, int *size) {
	FILE *f = fopen(filename, "r");
	char buf[MAX_EVENT_TEXT];
	readnum(f, buf);
	*size = atoi(buf);
	event *res = malloc(*size * sizeof(event));
	for(int i = 0; i < *size; i++) {
		readnum(f, buf);
		res[i].when = atol(buf);
		{
			int j = 0;
			for (; j < MAX_EVENT_TEXT && (buf[j] = fgetc(f)) != '\n' && buf[j] != EOF; j++) {}
			for (int k = j; k < MAX_EVENT_TEXT; k++) buf[k] = 0;
			strncpy(res[i].text, buf, j);
		}
	}
	fclose(f);
	return res;
}
