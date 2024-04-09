#include "scalp.h"

/*
Used with qsort. TODO turn off type error, such that cproc can compile this too.
*/
int timecompare(const void *v1, const void *v2) {
	event *e1 = (event *)v1;
	event *e2 = (event *)v2;
	return e1->when - e2->when;
}
