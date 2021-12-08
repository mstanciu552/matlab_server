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
  state->add_textDocument(json["params"]["textDocument"]["uri"],
                          json["params"]["textDocument"]);
}

void Server::did_close_cb(nlohmann::json json, State *state) {
  std::cout << "didClose" << std::endl;
  if (json["params"] == nullptr || json["params"]["textDocument"] == nullptr) {
    Error *err = new Error(json["id"], ErrorCode::Invalid_Params);
    post_json(err->to());
  }

  state->remove_textDocument(json["params"]["textDocument"]["uri"]);
}

void Server::did_change_cb(nlohmann::json json, State *state) {
  std::cout << "didClose" << std::endl;
  if (json["params"] == nullptr || json["params"]["textDocument"] == nullptr) {
    Error *err = new Error(json["id"], ErrorCode::Invalid_Params);
    post_json(err->to());
  }
  state->get_textDocument(json["params"]["textDocument"]["uri"])->textDocument =
      json["params"]["textDocument"];
}

void Server::formatting_cb(nlohmann::json json, State *state) {
  if (json["params"] == nullptr || json["params"]["textDocument"] == nullptr) {
    Error *err = new Error(json["id"], ErrorCode::Invalid_Params);
    post_json(err->to());
  }
}

void Server::init_methods() {
  struct map *didOpen = new struct map("textDocument/didOpen", did_open_cb);
  struct map *didClose = new struct map("textDocument/didClose", did_close_cb);
  struct map *didChange =
      new struct map("textDocument/didChange", did_change_cb);
  struct map *formatting =
      new struct map("textDocument/formatting", formatting_cb);

  this->state->new_method(didOpen);
  this->state->new_method(didClose);
  this->state->new_method(didChange);
  this->state->new_method(formatting);
}
