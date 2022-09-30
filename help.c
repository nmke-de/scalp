#include <unistd.h>
#include <string.h>

// Macro to make code more managable
#define print(str) write(0, (str), strlen((str)))

/*
shows help message
*/
void help(char *filename) {
	static const char *helpmsg = "scalp - a Simple CALendar Program\n\
see also: man 1 scalp\n\
Usage: scalp [SUBCOMMAND] [FILENAME]\n\
Running scalp without subcommand starts the daemon to notify you.\n\
	add\tadd a new entry\n\
	del\tdelete an entry\n\
	help\tshow this message\n\
	list\tlist all entries\n\
	prune\tremove all old entries\n\
	update\tupdate all running instances\n";
	print(helpmsg);
}
