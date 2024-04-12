#include <stdlib.h>

#include "scalp.h"

const char *getenv_default(const char *varname, const char *_default) {
	char *res = getenv(varname);
	if (res == NULL || *res == 0)
		return _default;
	return res;
}
