#include "methods.hpp"

std::vector<struct Map<std::string, std::function<void()>> *>
    methods_vector; // Vector of pointers to map

void methods::add_methods(std::string name, std::function<void()> callback) {
  struct Map<std::string, std::function<void()>> *element =
      new struct Map<std::string, std::function<void()>>(name, callback);

  methods_vector.push_back(element);
}

std::vector<table *> methods::init_methods(void) {
  add_methods("textDocument/didOpen", methods::define::did_open_cb);
  return methods_vector;
}

void methods::input::handle_input(nlohmann::json input) {
  if (input["method"] == nullptr)
    return;
  for (auto method : methods_vector) {
    if (method->key == input["method"]) {
      method->value();
      break;
    }
  }
}

void methods::define::did_open_cb() { std::cout << "Hello world!"; }
