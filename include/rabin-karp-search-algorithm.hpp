#pragma once

#include <string>
#include <list>

using std::string, std::list;

#define PRIME_NUMBER 101
#define ALPHABET_LENGTH 256


class RabinKarpSearchAlgorithm{
public:
    RabinKarpSearchAlgorithm(const string& pattern);

    // Returns list of first indexes of beginning pattern
    list<size_t> search(const string& text) const;

private:
    string pattern_;
    int pattern_hash_;
    int left_base_offset_;

    //The length of text is guaranteed that equals to length of pattern
    int get_hash(const char* input) const;

    //The length of text is guaranteed that equals to length of pattern
    bool compare_to_pattern(const char* text) const;

    int hash_for_symbol(char input, int prev_hash = 0) const;

    int rehash(int prev_hash, char prev, char next) const;
};
