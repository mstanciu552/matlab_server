#include "error.hpp"

Error::Error(int id, ErrorCode error) : jsonrpc("2.0"), id(id), error(error) {}

Error *from(std::string str) {
  nlohmann::json parsed = nlohmann::json::parse(str);
  if (parsed["id"] == nullptr)
    return nullptr;
  Error *err;

  try {
    err = new Error(parsed["id"], parsed["error"]);
  } catch (nlohmann::json::type_error &e) {
    if (e.id == 302) {
      Error *err = new Error(parsed["id"], ErrorCode::Invalid_Json_Conversion);
      post_json(err->to());
    }
  }

  return err;
}

nlohmann::json Error::to() {
  nlohmann::json jsonified = {{"jsonrpc", "2.0"}, {"id", id}, {"error", error}};
  return jsonified;
}
