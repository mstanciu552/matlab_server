#ifndef FORMATTING_H_
#define FORMATTING_H_

#include "../lib/json.hpp"
#include <iostream>
#include <vector>

class FormattingOptions {
public:
  unsigned int tabSize;
  bool insertSpaces;
  bool trimTrailingWhitespace;
  bool insertFinalNewline;
  bool trimFinalNewline;
  std::vector<nlohmann::json> key;

  FormattingOptions(unsigned int tabSize, bool insertSpaces,
                    bool trimTrailingWhitespace, bool insertFinalNewline,
                    bool trimFinalNewline, std::vector<nlohmann::json> key);

  FormattingOptions(nlohmann::json);
};

#endif
