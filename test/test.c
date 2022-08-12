#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../scalp.h"

void test_read_file_1() {
	int size;
	event *ev = read_file("test1.scalp", NULL, &size);
	assert(size == 1);
	assert(ev[0].when == 0);
	assert(strcmp(ev[0].text, "Test") == 0);
	free(ev);
}

void test_read_file_2() {
	int size;
	event *ev = read_file("test2.scalp", NULL, &size);
	assert(size == 2);
	assert(ev[0].when == 0);
	assert(strcmp(ev[0].text, "Hahatop") == 0);
	assert(ev[1].when == 1659511309);
	assert(strlen(ev[1].text) == 4);
	assert(strcmp(ev[1].text, "asda") == 0);
	free(ev);
}

void test_notify_send_1() {
	notify_send("Test.");
}

int main() {
	test_read_file_1();
	test_read_file_2();
	test_notify_send_1();
	char *msg = "All tests successful.\n";
	write(0, msg, strlen(msg));
	return 0;
}
