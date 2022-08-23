#include <unistd.h>
#include <signal.h>
// #include <stdlib.h>
#include "scalp.h"

int main(int argc, char **argv) {
	char *filename = argc < 2 ? "foo" : argv[1];
	scalpd(filename);
	return 0;
}
