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

  int max_calories[] = {0, 0, 0};
  int sum = 0;

  while (!file.eof()) {
    while (getline(file, line)) {
      try {
        if (line.empty()) {
          int least_calorie_index = 0;
          for (int i = 0; i < sizeof(max_calories) / sizeof(max_calories[0]);
               i++) {
            if (max_calories[i] < max_calories[least_calorie_index])
              least_calorie_index = i;
          }
          if (sum > max_calories[least_calorie_index])
            max_calories[least_calorie_index] = sum;
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
  ss << "The elves carrying the most calories carry " << max_calories[0] << ", "
     << max_calories[1] << ", and " << max_calories[2]
     << " calories respectively";
  log.info(ss.str());
  ss.str("");
  ss << "Collectively they carry "
     << max_calories[0] + max_calories[1] + max_calories[2] << " calories";
  log.info(ss.str());

  file.close();
}
