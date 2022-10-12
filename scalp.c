#include "scalp.h"
#include "config.h"

/*
Entry point of the program (duh.)
*/
int main(int argc, char **argv) {
	char *filename = default_file;
	// argparsing
	void (*mode)(char *) = scalpd;
	if (argc > 1) {
		if (strcmp(argv[1], "list") == 0)
			mode = list;
		else if (strcmp(argv[1], "add") == 0)
			mode = add;
		else if (strcmp(argv[1], "update") == 0)
			mode = trigger_update;
		else if (strcmp(argv[1], "del") == 0)
			mode = del;
		else if (strcmp(argv[1], "prune") == 0)
			mode = prune;
		else if (strcmp(argv[1], "help") == 0)
			mode = help;
		else if (strcmp(argv[1], "change") == 0)
			mode = change;
		else if (strcmp(argv[1], "move") == 0)
			mode = move;
		else if (strcmp(argv[1], "copy") == 0)
			mode = copy;
		else
			filename = argv[1];
	}
	if (argc > 2 && strcmp(filename, default_file) == 0)
		filename = argv[2];
	// Goto a routine according to the given subcommand.
	mode(filename);
	return 0;
}
