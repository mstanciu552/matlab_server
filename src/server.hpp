#ifndef SERVER_H_
#define SERVER_H_

#include "formatting.hpp"
#include "methods.hpp"
#include "state.hpp"

class Server {
private:
  State *state;
  Method *methods;
  static void did_open_cb(nlohmann::json, State *);
  static void did_close_cb(nlohmann::json, State *);
  static void did_change_cb(nlohmann::json, State *);
  static void did_save_cb(nlohmann::json, State *);
  static void formatting_cb(nlohmann::json, State *);
  void init_methods();

public:
  Server();
  State *get_state() { return state; }
  Method *get_methods() { return methods; }
};

#endif
