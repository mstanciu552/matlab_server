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
  static void did_open_cb(nlohmann::json params);
  static void did_close_cb(nlohmann::json params);
  static void did_change_cb(nlohmann::json params);
  static void did_save_cb(nlohmann::json params);

public:
  Method(State *);
  std::vector<struct map *> init_methods();
  void add_methods(std::string, std::function<void(nlohmann::json)>);
  void handle_input(nlohmann::json);
};

#endif
