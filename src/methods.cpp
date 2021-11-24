#include "methods.hpp"

Method::Method(State *state) : state(state) {}

void Method::add_methods(
    std::string name,
    std::function<void(nlohmann::json, State *state)> callback) {

  struct map *element = new struct map(name, callback);

  this->state->new_method(element);
}
