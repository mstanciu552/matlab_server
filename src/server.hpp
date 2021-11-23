#ifndef SERVER_H_
#define SERVER_H_

#include "methods.hpp"
#include "state.hpp"

class Server {
private:
  State *state;
  Method *methods;

public:
  Server();
  State *get_state() { return state; }
  Method *get_methods() { return methods; }
};

#endif
