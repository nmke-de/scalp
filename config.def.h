#include "scalp.h"

#ifndef CONFIG_H
#define CONFIG_H

// Configure warning/notification messages. First comes the number of seconds before the actual event, then the message title displayed. scalp expects this array to end on a warning with time 0.
#define warns {\
	{86400, "Tomorrow!"},\
	{3600, "In an hour!"},\
	{600, "In ten minutes!"},\
	{0, "NOW!"},\
}

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
// #define fno_repeat
// #define fno_update
// #define fno_daemon

#endif
