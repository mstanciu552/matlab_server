#include "utils.hpp"

nlohmann::json get_json() {
  nlohmann::json json;
  std::cin >> json;
  return json;
}

void post_json(nlohmann::json json) { std::cout << json << std::endl; }
