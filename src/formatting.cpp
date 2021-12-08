#include "formatting.hpp"

FormattingOptions::FormattingOptions(unsigned int tabSize, bool insertSpaces,
                                     bool trimTrailingWhitespace,
                                     bool insertFinalNewline,
                                     bool trimFinalNewline,
                                     std::vector<nlohmann::json> key) {
  this->tabSize = tabSize;
  this->insertSpaces = insertSpaces;
  this->trimTrailingWhitespace = trimTrailingWhitespace;
  this->insertFinalNewline = insertFinalNewline;
  this->trimFinalNewline = trimFinalNewline;
  this->key = key;
}
