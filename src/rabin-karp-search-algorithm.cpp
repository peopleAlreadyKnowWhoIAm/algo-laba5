#include "rabin-karp-search-algorithm.hpp"

RabinKarpSearchAlgorithm::RabinKarpSearchAlgorithm(const string& pattern) {
  pattern_ = pattern;
  pattern_hash_ = get_hash(pattern.c_str());

  unsigned int tmp_hash = 1;
  for (int i = pattern.length() - 2; i >= 0; i--) {
    tmp_hash = hash_for_symbol(0, tmp_hash);
  }

  left_base_offset_ = tmp_hash;
}

list<size_t> RabinKarpSearchAlgorithm::search(const string& text) const {
  size_t length = pattern_.length();
  if (text.length() < length) {
    return list<size_t>();
  }
  const char* ctext = text.c_str();

  int hash = get_hash(ctext);
  list<size_t> out;
  if (hash == pattern_hash_ && compare_to_pattern(ctext)) out.push_back(0);
  for (size_t i = 1; i < text.length() - length; i++) {
    hash = rehash(hash, ctext[i - 1], ctext[i + length - 1]);
    if (hash == pattern_hash_ && compare_to_pattern(&ctext[i])) out.push_back(i);
  }

  return out;
}

int RabinKarpSearchAlgorithm::get_hash(const char* input) const {
  size_t length = pattern_.length();

  int buf = 0;

  for (size_t i = 0; i < length; i++) {
    buf = hash_for_symbol(input[i], buf);
  }

  return buf;
}

int RabinKarpSearchAlgorithm::hash_for_symbol(char input, int prev) const {
  return (prev * ALPHABET_LENGTH + input) % PRIME_NUMBER;
}

int RabinKarpSearchAlgorithm::rehash(int prev_hash, char prev, char next) const {
  int a = ((prev_hash - left_base_offset_ * prev % PRIME_NUMBER) * ALPHABET_LENGTH + next) %
          PRIME_NUMBER;
  if (a < 0) a += PRIME_NUMBER;
  return a;
}

bool RabinKarpSearchAlgorithm::compare_to_pattern(const char* text) const {
  for (size_t i = 0; i < pattern_.length(); i++) {
    if (text[i] != pattern_[i]) return false;
  }
  return true;
}