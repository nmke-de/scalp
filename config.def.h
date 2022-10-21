#include "scalp.h"

#ifndef CONFIG_H
#define CONFIG_H

// TODO use struct
#define warn_time {86400, 3600, 600, 0}
#define warn_title {"Tomorrow!", "In an hour!", "In ten minutes!", "NOW!"}
notification warns[] = {
	{86400, "Tomorrow!"},
	{3600, "In an hour!"},
	{600, "In ten minutes!"},
	{0, "NOW!"},
};

#define notify_command {"notify-send", "-t", "300000", title, msg, NULL}

#define default_file "foo"

// Uncomment to disable features
// #define fno_add
// #define fno_change
// #define fno_copy
// #define fno_del
// #define fno_help
// #define fno_list
// #define fno_move
// #define fno_prune
// #define fno_update
// #define fno_daemon

#endif
