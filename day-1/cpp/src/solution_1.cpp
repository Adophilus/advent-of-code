#include <fstresam>
#include <iostream>
#include <string>

int main() {
  const std::string input_file = "input.txt";
  std::fstream file(input_file);

  file.close();
}
