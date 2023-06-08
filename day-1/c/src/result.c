#include "./lib/result.h"
#include <stdlib.h>

Result Ok(void *value) { return (Result){.some = value, .err = NULL}; }

Result Err(char *err) { return (Result){.some = NULL, .err = err}; }
