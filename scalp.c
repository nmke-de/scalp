#include <string.h>
#include "scalp.h"

int main(int argc, char **argv) {
	char *filename = "foo";
	void (*mode)(char *) = scalpd;
	if (argc > 1) {
		if (strcmp(argv[1], "list") == 0)
			mode = list;
		else
			filename = argv[1];
	}
	if (argc > 2 && strcmp(filename, "foo") == 0)
		filename = argv[2];
	mode(filename);
	return 0;
}
