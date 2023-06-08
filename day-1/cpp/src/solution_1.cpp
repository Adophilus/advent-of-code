#include "./lib/logger.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  const std::string input_file = "input.txt";
  Logger log;
  std::string line;
  std::fstream file(input_file);

  if (!file.is_open()) {
    log.error("Failed to open file!");
    return 1;
  }

  int max = 0;
  int sum = 0;

  while (!file.eof()) {
    while (getline(file, line)) {
      try {
        if (line.empty()) {
          if (sum > max)
            max = sum;
          sum = 0;
          continue;
        }

        int number = std::stoi(line);
        sum += number;
      } catch (std::exception &e) {
        std::stringstream ss;
        ss << "Conversion error: " << e.what();
        log.error(ss.str());
        return 1;
      }
    }
  }

  std::stringstream ss;
  ss << "The elf carrying the most calories carries " << max << " calories";
  log.info(ss.str());

  file.close();
}
