#include "scalp.h"

/*
Used with qsort. TODO turn off type error, such that cproc can compile this too.
*/
int timecompare(const event *e1, const event *e2) {
	return e1->when - e2->when;
}
