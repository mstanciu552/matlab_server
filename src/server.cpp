#include "server.hpp"

Server::Server() {
  state = new State();
  methods = new Method(state);
}
