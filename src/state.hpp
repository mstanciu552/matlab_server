#ifndef STATE_H_
#define STATE_H_

#include "../lib/json.hpp"
#include "utils.hpp"
#include <functional>
#include <iostream>

struct textDocument {
  std::string uri;
  std::string textDocument;
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
  void new_method(struct map *);
};

struct map {
  std::string key;
  std::function<void(nlohmann::json, State *)> value;

  map(std::string key, std::function<void(nlohmann::json, State *)> value)
      : key(key), value(value) {}
};

#endif
