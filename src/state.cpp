#include "state.hpp"

State::State() {}

void State::loop() {
  bool running = true;
  while (running) {
    if (!handle_input(get_json()))
      running = false; // FIXME Send error message instead
  }
}

bool State::handle_input(nlohmann::json input) {
  if (input["method"] == nullptr) {
    std::cout << "method problem" << std::endl;
    return false;
  }
  for (struct map *method : methods_vector) {
    std::cout << method << std::endl;
    if (method->key == input["method"]) {
      method->value(input);
      break;
    }
  }
  return true;
}