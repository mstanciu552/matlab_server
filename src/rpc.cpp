#include "rpc.hpp"

Request::Request(int id, std::string method, nlohmann::json params)
    : jsonrpc("2.0"), id(id), method(method), params(params) {}

Request *Request::from(std::string str) {
  nlohmann::json parsed = nlohmann::json::parse(str);
  Request *req;
  try {
    req = new Request(parsed["id"], parsed["method"], parsed["params"]);
  } catch (const nlohmann::detail::type_error) {
    std::cout << "Incorrect format for converting JSON to Request object"
              << std::endl;
    Error *err = new Error(parsed["id"], ErrorCode::Invalid_Json_Conversion);
    post_json(err->to());
  }
  return req;
}

nlohmann::json Request::to() {
  nlohmann::json jsonified = {
      {"jsonrpc", "2.0"}, {"id", id}, {"method", method}, {"params", params}};
  return jsonified;
}

Response::Response(int id, nlohmann::json result)
    : jsonrpc("2.0"), id(id), result(result) {}

Response *Response::from(std::string str) {
  nlohmann::json parsed = nlohmann::json::parse(str);
  Response *req;
  try {
    req = new Response(parsed["id"], parsed["result"]);
  } catch (const nlohmann::detail::type_error) {
    std::cout << "Incorrect format for converting JSON to Response object"
              << std::endl;
    Error *err = new Error(parsed["id"], ErrorCode::Invalid_Json_Conversion);
    post_json(err->to());
  }
  return req;
}

nlohmann::json Response::to() {
  nlohmann::json jsonified = {
      {"jsonrpc", "2.0"}, {"id", id}, {"result", result}};
  return jsonified;
}

void Request::print() { std::cout << to() << std::endl; }
void Response::print() { std::cout << to() << std::endl; }
