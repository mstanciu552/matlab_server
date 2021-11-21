#ifndef METHODS_H_
#define METHODS_H_

#include <functional>
#include <iostream>
#include <vector>

#define CB(func)                                                               \
  if (func == 1)                                                               \
    return 1;

template <typename T, typename F> struct Map {
  T key;
  F value;
  Map(T key, F value) : key(key), value(value) {}
};

typedef struct Map<std::string, std::function<void()>> table;

namespace methods {
namespace define {
void did_open_cb();
}
std::vector<table *> init_methods();
void add_methods(std::string, std::function<void()>);
} // namespace methods

#endif
