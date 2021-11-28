#ifndef STATE_H_
#define STATE_H_

#include "../lib/json.hpp"
#include "error.hpp"
#include "utils.hpp"
#include <functional>
#include <iostream>

struct textDocumentItem {
  std::string uri;
  nlohmann::json textDocument;
  textDocumentItem(std::string uri, nlohmann::json textDocument)
      : uri(uri), textDocument(textDocument) {}
};

class State {
private:
  std::vector<struct textDocumentItem *> textDocument;
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
  void add_textDocument(std::string, nlohmann::json);
};

struct map {
  std::string key;
  std::function<void(nlohmann::json, State *)> value;

  map(std::string key, std::function<void(nlohmann::json, State *)> value)
      : key(key), value(value) {}
};

#endif
