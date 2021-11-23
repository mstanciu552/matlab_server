#ifndef STATE_H_
#define STATE_H_

#include "../lib/json.hpp"
#include "utils.hpp"
#include <iostream>

struct textDocument {
  std::string uri;
  std::string textDocument;
};

struct map {
  std::string key;
  void (*value)(nlohmann::json);

  map(std::string key, void (*value)(nlohmann::json))
      : key(key), value(value) {}
};

class State {
private:
  struct textDocument textDocument;
  std::vector<struct map *> methods_vector;

public:
  State();
  void loop();
  auto get_methods() { return methods_vector; }
  void set_methods(std::vector<struct map *> methods_vector) {
    methods_vector = methods_vector;
  }
  bool handle_input(nlohmann::json);
};

#endif
