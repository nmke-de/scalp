#include <string.h>
#include <stdlib.h>
#include "scalp.h"

void notify_send(const char *msg) {
	system(strcat("notify-send ", msg));
}
