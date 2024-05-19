#include <filesystem>
#include <iostream>

int main() {
  std::filesystem::path p("./some_file");

  std::cout << p << "exists: " << std::boolalpha << std::filesystem::exists(p)
            << std::endl;

  std::cout << p << "file: " << std::boolalpha
            << std::filesystem::is_regular_file(p) << std::endl;

  std::cout << p << "directory: " << std::boolalpha
            << std::filesystem::is_directory(p) << std::endl;

  std::cout << std::filesystem::current_path() << std::endl;
  std::cout << p.relative_path() << std::endl;
  std::cout << std::filesystem::absolute(p) << std::endl;
  std::cout << std::filesystem::canonical(p) << std::endl;
}