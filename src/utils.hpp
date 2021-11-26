#ifndef UTILS_H_
#define UTILS_H_

#include "../lib/json.hpp"
#include <iostream>
#include <lua.hpp>
#include <vector>

nlohmann::json get_json();
void post_json(nlohmann::json);
void exec_lua(std::string);

#endif
