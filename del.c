#include <unistd.h>
#include <string.h>
#include "scalp.h"

#define print(str) write(0, (str), strlen((str)))
#define input(var, limit) read(1, (var), (limit))

void del(char *) {
	;
}