#ifndef SCALP_H
#define SCALP_H
#include <time.h>

typedef struct {
	time_t when;
	char *text;
} event;

void notify_send(char *);
event *read_file(const char *); // TODO change signature before use

#endif
