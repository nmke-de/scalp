#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scalp.h"

#define readnum (f, buf) ;{int j = 0; for (; j < MAX_EVENT_TEXT && (buf[j] = fgetc(f)) >= '0' && buf[j] <= '9'; j++) {} buf[j] = 0;}

event *read_file (const char *filename, int *size) {
	FILE *f = fopen(filename, "r");
	//char *buf = malloc(sizeof(char) * 512);
	char buf[MAX_EVENT_TEXT];
	//int j = 0;
	//for (; j < MAX_EVENT_TEXT && (buf[i] = fgetc(f)) >= '0' && buf[i] <= '9'; i++) {}
	////for (; i < MAX_EVENT_TEXT; i++) buf[i] = 0;
	//buf[++j] = 0;
	readnum(f, buf);
	//getdelim(&buf, sizeof(char) * 512, f);
	*size = atoi(buf);
	event *res = malloc(*size);
	for(int i = 0; i < *size; i++) {
		readnum(f, buf);
		//getdelim(&buf, sizeof(char) * 512, '\t', f);
		res[i].when = atol(buf);
		//getdelim(&buf, sizeof(char) * 512, '\n', f);
		{
			int j = 0;
			for (; j < MAX_EVENT_TEXT && (buf[j] = fgetc(f)) != '\n' && buf[j] != EOF; j++) {}
			buf[j] = 0;
		}
		strncpy(res[i].text, buf, MAX_EVENT_TEXT);
	}
	fclose(f);
	return res;
}
