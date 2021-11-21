#ifndef UTILS_H_
#define UTILS_H_

#include "../lib/json.hpp"
#include <iostream>
#include <vector>

nlohmann::json get_json();
void post_json(nlohmann::json);

#endif
