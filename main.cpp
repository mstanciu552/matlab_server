#include "src/rpc.hpp"
#include "src/server.hpp"
#include <iostream>

int main() {
  Server *server = new Server();
  server->get_state()->loop();

  return 0;
}
