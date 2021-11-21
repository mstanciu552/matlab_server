#include "src/methods.hpp"
#include "src/rpc.hpp"
#include <iostream>

int main() {
  auto methods_vector = methods::init_methods();
  std::string json_string = "{\"jsonrpc\": \"2.0\", \"id\": 1, \"method\": "
                            "\"textDocument/didOpen\", \"params\": \"\"}";

  return 0;
}
