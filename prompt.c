#include <unistd.h>
#include <string.h>
#include "scalp.h"

/*
Prompts the user with msg to input text in to a buffer buf with bufsize length. Returns the length of input.
*/
int prompt(char *buf, int bufsize, char *msg) {
	// User input
	print(msg);
	int rl = input(buf, bufsize);
	// Check for overflow
	if (rl == bufsize) {
		buf[rl - 1] = 0;
		// Remove characters that are still in the input buffer
		char junk[16];
		int rl2;
		do {
			rl2 = input(junk, 16);
		} while (junk[rl2 - 1] != '\n');
	}
	return rl;
}
