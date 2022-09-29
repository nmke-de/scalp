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

void notify_send(char *, char *);
event *read_file(const char *, event *, int *);
int timecompare(const void *, const void *);
int append(char *, char *, int, char *, int);
int rm(char *, event *, int, int *, int);

// Different modes (see main() in scalp.c)
void scalpd(char *);
void list(char *);
void add(char *);
void trigger_update(char *);
void del(char *);
void prune(char *);
void help(char *);

#ifdef __cplusplus
}
#endif

#endif
