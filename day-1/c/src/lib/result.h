#ifndef RESULT_H
#define RESULT_H

typedef struct Result {
  void *some;
  char *err;
} Result;

Result Ok(void *value);
Result Err(char *err);

#endif
