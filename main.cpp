#include "src/rpc.hpp"
#include <iostream>

int main() {
  std::string json_string = "{\"jsonrpc\": \"2.0\", \"id\": 1, \"method\": \
                               \"textDocument\", \"params\": \"\"}";
  Request *req = Request::from(json_string);
  std::cout << req->to() << std::endl;
  return 0;
}
