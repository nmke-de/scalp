#include <unistd.h>
#include <stdlib.h>
#include "scalp.h"

int main() {
	time_t t = time(NULL);
	int size;
	event *ev = read_file("foo", &size); // TODO change file name
	//event one_minute_from_now;
	//one_minute_from_now.when = t + 60;
	//one_minute_from_now.text = "One Minute has passed.";
	for(;; t = time(NULL)) {
		//if(t == one_minute_from_now.when) notify_send(one_minute_from_now.text);
		for(int i = 0; i < size; i++) if(t == ev[i].when) notify_send(ev[i].text);
		sleep(1);
	}
	free(ev);
	return 0;
}
