#include "src/rpc.hpp"
#include "src/server.hpp"
#include <iostream>

// FIXME Function pointer problem

int main() {
  Server *server = new Server();
  exec_lua();
  server->get_state()->loop();

  return 0;
}
