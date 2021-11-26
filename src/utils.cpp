#include "utils.hpp"

nlohmann::json get_json() {
  nlohmann::json json;
  std::cin >> json;
  return json;
}

void post_json(nlohmann::json json) { std::cout << json << std::endl; }

void exec_lua(std::string path) {
  lua_State *lua_state;
  lua_state = luaL_newstate();
  static const luaL_Reg lualibs[] = {{"base", luaopen_base}, {NULL, NULL}};
  const luaL_Reg *lib = lualibs;
  for (; lib->func != NULL; lib++) {
    lib->func(lua_state);
    lua_settop(lua_state, 0);
  }
  luaL_dofile(lua_state, path.c_str());
  lua_close(lua_state);
}
