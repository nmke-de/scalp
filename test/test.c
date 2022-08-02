#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../scalp.h"

void test_read_file_1() {
	int size;
	event *ev = read_file("test1.scalp", &size);
	assert(size == 1);
	assert(ev[0].when == 0);
	assert(strcmp(ev[0].text, "Test") == 0);
	free(ev);
}

int main() {
	test_read_file_1();
	char *msg = "All tests successful.\n";
	write(0, msg, strlen(msg));
	return 0;
}
