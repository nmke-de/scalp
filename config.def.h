#include "scalp.h"

#ifndef CONFIG_H
#define CONFIG_H

// TODO use struct
#define warn_time {86400, 3600, 600, 0}
#define warn_title {"Tomorrow!", "In an hour!", "In ten minutes!", "NOW!"}

#define notify_command {"notify-send", "-t", "300000", title, msg, NULL}

#define default_file "foo"

#endif
