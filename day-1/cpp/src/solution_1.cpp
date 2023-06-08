#include <fstresam>
#include <iostream>
#include <string>

int main() {
  const std::string input_file = "input.txt";
  std::string line;
  std::fstream file(input_file);

  if (!file.is_open()) {
    print_error("Failed to open file!");
    return 1;
  }

  line = file.get();
  cout << line << std::endl;

  // while (getline(file, line)) {
  //   std::cout << line << std::endl;
  // }

  file.close();
}
