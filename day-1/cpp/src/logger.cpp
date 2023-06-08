#include "./lib/logger.hpp"
#include <iostream>
#include <string>

const std::string Logger::FG_RESET = "\033[0m";
const std::string Logger::FG_RED = "\033[31m";
const std::string Logger::FG_GREEN = "\033[32m";
const std::string Logger::FG_YELLOW = "\033[33m";
const std::string Logger::FG_BLUE = "\033[34m";
const std::string Logger::BG_RESET = "\033[49m";
const std::string Logger::BG_RED = "\033[41m";
const std::string Logger::BG_GREEN = "\033[42m";
const std::string Logger::BG_YELLOW = "\033[43m";
const std::string Logger::BG_BLUE = "\033[44m";

void Logger::info(const std::string &msg) {
  std::cout << BG_BLUE << "INFO" << BG_RESET << " " << msg << std::endl;
}

void Logger::error(const std::string &msg) {
  std::cout << BG_RED << "ERROR" << BG_RESET << " " << msg << std::endl;
}
