#ifndef SCALP_H
#define SCALP_H
#include <time.h>

#define MAX_EVENT_TEXT 512

typedef struct {
	time_t when;
	char text[MAX_EVENT_TEXT];
} event;

void notify_send(char *);
event *read_file(const char *, int *);

#endif
