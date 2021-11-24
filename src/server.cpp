#include "server.hpp"

Server::Server() {
  state = new State();
  methods = new Method(state);
  init_methods();
}

void Server::did_open_cb(nlohmann::json json, State *state) {
  std::cout << "didOpen" << std::endl;
  Error *err;
  if (json["params"] == nullptr || json["params"]["textDocument"] == nullptr) {
    err = new Error(json["id"], ErrorCode::Invalid_Params);
    post_json(err->to());
  }
  // TODO Add to global state
  state->add_textDocument(json["params"]["textDocument"]["uri"],
                          json["params"]["textDocument"]);
}

void Server::init_methods() {
  struct map *didOpen = new struct map("textDocument/didOpen", did_open_cb);
  this->state->new_method(didOpen);
}
