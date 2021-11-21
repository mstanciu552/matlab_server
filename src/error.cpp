#include "error.hpp"

Error::Error(int id, ErrorCode error) : jsonrpc("2.0"), id(id), error(error) {}

Error *from(std::string str) {
  nlohmann::json parsed = nlohmann::json::parse(str);
  Error *err;

  try {
    err = new Error(parsed["id"], parsed["error"]);
  } catch (const nlohmann::detail::type_error) {
    std::cout << "Incorrect format for converting JSON to Error object"
              << std::endl;
    exit(1);
    // TODO Should send an error code from rpc specifications
  }

  return err;
}

nlohmann::json Error::to() {
  nlohmann::json jsonified = {{"jsonrpc", "2.0"}, {"id", id}, {"error", error}};
  return jsonified;
}
