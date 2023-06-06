#ifdef _WIN32
#define LINE_ENDING "\r\n"
#else
#define LINE_ENDING "\n"
#endif

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_BG_BLACK "\x1b[40m"
#define ANSI_BG_RED "\x1b[41m"
#define ANSI_BG_GREEN "\x1b[42m"
#define ANSI_BG_YELLOW "\x1b[43m"
#define ANSI_BG_BLUE "\x1b[44m"
#define ANSI_BG_MAGENTA "\x1b[45m"
#define ANSI_BG_CYAN "\x1b[46m"
#define ANSI_BG_WHITE "\x1b[47m"
#define ANSI_RESET "\x1b[0m"

// #include <glib-2.0/glib.h>
// #include "../lib/glib-2.9.6/glib/glib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Result {
  void *some;
  char *err;
} typedef Result;

void print_error(char *err) {
  printf(ANSI_BG_RED "ERROR" ANSI_COLOR_RESET " %s\n", err);
}

void print_info(char *msg) {
  printf(ANSI_BG_BLUE "INFO" ANSI_COLOR_RESET " %s\n", msg);
}

Result string_to_int(char *str) {
  char *endptr;
  int value;

  value = strtol(str, &endptr, 10);
  if (str == endptr || *endptr != '\0') {
    Result result = {NULL, strdup("Failed to parse string to int")};
    return result;
  }
  Result result = {(void *)(intptr_t)value, NULL};
  return result;
}

int main() {
  char *input_file_path = "input.txt";
  FILE *fptr = fopen(input_file_path, "r");
  char buffer[100];
  int i = 0;
  int max = 0;
  int sum = 0;
  while (fgets(buffer, sizeof buffer, fptr)) {
    int line_length = strcspn(buffer, LINE_ENDING);
    char line[100];

    strncpy(line, buffer, line_length);
    line[line_length - 1] = '\0';

    if (line_length == 0) {
      if (sum > max)
        max = sum;
      sum = 0;
      continue;
    }

    Result result = string_to_int(line);
    if (result.err != NULL) {
      char error_message[100];
      sprintf(error_message, "Failed to convert number %s", line);
      print_error(result.err);
      print_error(error_message);

      free(result.err);
      return 1;
    }

    int number = (int)(intptr_t)result.some;

    buffer[0] = '\0';
    line[0] = '\0';

    sum += number;
    i += 1;
  }

  char msg[100];
  sprintf(msg,
          "The elf carrying the max number of calories carries %d calories",
          max);
  print_info(msg);

  fclose(fptr);
}
