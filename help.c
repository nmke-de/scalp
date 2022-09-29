#include <unistd.h>
#include <string.h>

// Macro to make code more managable
#define print(str) write(0, (str), strlen((str)))

/*
shows help message
*/
void help(char *filename) {
	print("scalp - a Simple CALendar Program\n");
	print("see also: man 1 scalp\n");
	print("Usage: scalp [SUBCOMMAND] [FILENAME]\n");
	print("Running scalp without subcommand starts the daemon to notify you.\n");
	print("\tadd\tadd a new entry\n");
	print("\tdel\tdelete an entry\n");
	print("\thelp\tshow this message\n");
	print("\tlist\tlist all entries\n");
	print("\tprune\tremove all old entries\n");
	print("\tupdate\tupdate all running instances\n");
}
