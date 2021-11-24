#include "methods.hpp"

Method::Method(State *state) : state(state) {
  state->set_methods(init_methods());
}

void Method::add_methods(std::string name,
                         std::function<void(nlohmann::json)> callback) {
  struct map *element = new struct map(name, callback);

  state->new_method(element);
}

std::vector<struct map *> Method::init_methods() {
  std::cout << &Method::did_change_cb << std::endl;
  add_methods("textDocument/didOpen", &Method::did_open_cb);
  return state->get_methods();
}

void Method::did_open_cb(nlohmann::json json) {
  std::cout << "didOpen" << std::endl;
  Error *err;
  if (json["params"] == nullptr || json["params"]["textDocument"] == nullptr) {
    err = new Error(json["id"], ErrorCode::Invalid_Params);
    post_json(err->to());
  }
  // TODO Add to global state
}
