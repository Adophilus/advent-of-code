#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
  static void info(const std::string &message);
  static void error(const std::string &message);

private:
  static const std::string FG_RESET;
  static const std::string FG_RED;
  static const std::string FG_GREEN;
  static const std::string FG_YELLOW;
  static const std::string FG_BLUE;
  static const std::string BG_RESET;
  static const std::string BG_RED;
  static const std::string BG_GREEN;
  static const std::string BG_YELLOW;
  static const std::string BG_BLUE;
};

#endif // LOGGER_H
