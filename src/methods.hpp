#ifndef METHODS_H_
#define METHODS_H_

#include "../lib/json.hpp"
#include "error.hpp"
#include "state.hpp"
#include <functional>
#include <iostream>
#include <vector>

class Method {
private:
  State *state;

public:
  Method(State *);
  std::vector<struct map *> init_methods();
  void add_methods(std::string, std::function<void(nlohmann::json, State *)>);
  void handle_input(nlohmann::json);
};

#endif
