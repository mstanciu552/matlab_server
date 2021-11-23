#include "methods.hpp"

Method::Method(State *state) : state(state) {
  state->set_methods(init_methods());
}

void Method::add_methods(std::string name,
                         std::function<void(nlohmann::json)> callback) {
  struct map *element = new struct map(name, callback);

  state->get_methods().push_back(element);
}

std::vector<struct map *> Method::init_methods() {
  std::cout << "init_methods" << std::endl;
  add_methods("textDocument/didOpen", &did_open_cb);
  return state->get_methods();
}

void Method::did_open_cb(nlohmann::json json) {
  Error *err;
  if (json["params"] == nullptr || json["params"]["textDocument"] == nullptr) {
    err = new Error(json["id"], ErrorCode::Invalid_Params);
    post_json(err->to());
  }
  free(err);
  // TODO Add to global state
  std::cout << "didOpen" << std::endl;
}
