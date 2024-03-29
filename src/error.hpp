#ifndef ERROR_H_
#define ERROR_H_

#include "../lib/json.hpp"
#include "utils.hpp"
#include <iostream>

typedef enum {
  Parse_Error = -32700,
  Invalid_Request = -32600,
  Method_not_Found = -32601,
  Invalid_Params = -32602,
  Internal_Error = -32603,
  Invalid_Json_Conversion = -32000
} ErrorCode;

class Error {
private:
  std::string jsonrpc;
  int id;
  ErrorCode error;

public:
  Error(int, ErrorCode);
  static Error *from(std::string);
  nlohmann::json to();
};

#endif
