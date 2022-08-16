#ifndef SCALP_H
#define SCALP_H
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_EVENT_TEXT 512

typedef struct {
	time_t when;
	char text[MAX_EVENT_TEXT];
} event;

void notify_send(char *);
event *read_file(const char *, event *, int *);
void sighandle(int);

struct {
	event *ev;
	int size;
	char *filename;
} evlist = {
	NULL, 0, "foo"
};

#ifdef __cplusplus
}
#endif

#endif
