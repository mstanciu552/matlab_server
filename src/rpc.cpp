#include "rpc.hpp"

Request::Request(int id, std::string method, nlohmann::json params)
    : id(id), method(method), params(params) {}

Request *Request::from(std::string str) {
  nlohmann::json parsed = nlohmann::json::parse(str);
  Request *ret = (Request *)&parsed;
  return ret;
}

nlohmann::json Request::to() {
  nlohmann::json jsonified = {
      {"jsonrpc", "2.0"}, {"id", id}, {"method", method}, {"params", params}};
  return jsonified;
}

Response *Response::from(std::string str) {
  auto parsed = nlohmann::json::parse(str);
  auto ret = (Response *)&parsed;
  return ret;
}

nlohmann::json Response::to() {
  nlohmann::json jsonified = {
      {"jsonrpc", "2.0"}, {"id", id}, {"result", result}};
  return jsonified;
}

void Request::print() { std::cout << to() << std::endl; }
void Response::print() { std::cout << to() << std::endl; }
