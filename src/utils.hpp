#ifndef UTILS_H_
#define UTILS_H_

#include "../lib/json.hpp"
#include <iostream>
#include <vector>

std::vector<std::string> split(std::string, char);

nlohmann::json get_json();
void post_json(nlohmann::json);

#endif
