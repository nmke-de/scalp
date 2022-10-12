#include "scalp.h"
#include "config.h"

/*
Entry point of the program (duh.)
*/
int main(int argc, char **argv) {
	char *filename = default_file;
	// argparsing
#ifndef fno_daemon
	void (*mode)(char *) = scalpd;
#else
	void (*mode)(char *) = NULL;
#endif
	if (argc > 1) {
#ifndef fno_list
		if (strcmp(argv[1], "list") == 0)
			mode = list;
		else
#endif
#ifndef fno_add
		    if (strcmp(argv[1], "add") == 0)
			mode = add;
		else
#endif
#ifndef fno_update
		    if (strcmp(argv[1], "update") == 0)
			mode = trigger_update;
		else
#endif
#ifndef fno_del
		    if (strcmp(argv[1], "del") == 0)
			mode = del;
		else
#endif
#ifndef fno_prune
		    if (strcmp(argv[1], "prune") == 0)
			mode = prune;
		else
#endif
#ifndef fno_help
		    if (strcmp(argv[1], "help") == 0)
			mode = help;
		else
#endif
#ifndef fno_change
		    if (strcmp(argv[1], "change") == 0)
			mode = change;
		else
#endif
#ifndef fno_move
		    if (strcmp(argv[1], "move") == 0)
			mode = move;
		else
#endif
#ifndef fno_copy
		    if (strcmp(argv[1], "copy") == 0)
			mode = copy;
		else
#endif
			filename = argv[1];
	}
	if (argc > 2 && strcmp(filename, default_file) == 0)
		filename = argv[2];
	// Goto a routine according to the given subcommand.
#ifdef fno_daemon
	if (mode == NULL)
		return 1;
#endif
	mode(filename);
	return 0;
}
