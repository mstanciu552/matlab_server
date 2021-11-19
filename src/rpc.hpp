#ifndef RPC_H_
#define RPC_H_

#include "../lib/json.hpp"
#include <iostream>
#include <vector>

class Request {
private:
  std::string jsonrpc;
  int id;
  std::string method;
  nlohmann::json params;

public:
  Request(int, std::string, nlohmann::json);
  void print();
  static Request *from(std::string);
  nlohmann::json to();
  std::string get_method() { return method; }
};

class Response {
private:
  std::string jsonrpc;
  int id;
  nlohmann::json result;

public:
  Response(int, void *);
  void print();
  static Response *from(std::string);
  nlohmann::json to();
};

#endif
