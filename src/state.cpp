#include "state.hpp"

State::State() {}

void State::loop() {
  bool running = true;
  while (running) {
    handle_input(get_json());
    break;
  }
}

bool State::handle_input(nlohmann::json input) {
  if (input["method"] == nullptr) {
    Error *err = new Error(input["id"], ErrorCode::Invalid_Request);
    post_json(err->to());
    return false;
  }
  for (struct map *method : methods_vector) {
    if (method->key == input["method"]) {
      method->value(input, this);
      break;
    }
  }
  return true;
}

void State::new_method(struct map *method) { methods_vector.push_back(method); }

void State::add_textDocument(std::string name, nlohmann::json textDocument) {
  this->textDocument.push_back(new struct textDocumentItem(name, textDocument));
}

void State::remove_textDocument(std::string name) {
  for (auto el : this->textDocument)
    if (el->uri == name) {
      auto status =
          remove(this->textDocument.begin(), this->textDocument.end(), el);
      break;
    }
}

nlohmann::json State::get_state() {
  nlohmann::json json;
  json["textDocument"] = {this->textDocument[0]->textDocument,
                          this->textDocument[0]->uri};
  return json;
}

struct textDocumentItem *State::get_textDocument(std::string uri) {
  for (auto el : this->textDocument)
    if (el->uri == uri)
      return el;
  return nullptr;
}
