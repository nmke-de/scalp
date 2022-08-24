#include "scalp.h"

int timecompare(event *e1, event *e2) {
	return e1->when - e2->when;
}
