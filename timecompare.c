#include "scalp.h"

int timecompare(const event *e1, const event *e2) {
	return e1->when - e2->when;
}
