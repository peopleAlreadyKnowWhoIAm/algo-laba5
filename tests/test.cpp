#include <gtest/gtest.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>

#include "rabin-karp-search-algorithm.hpp"

using std::cout, std::endl, std::list, std::ifstream;

clock_t SetUpClock() { return clock(); }

void TearDownClock(clock_t time) {
  time = clock() - time;
  cout << "The time for the test: " << time << endl;
}

TEST(RobinKarpSearch, generated_string_with_same_hash) {
  ifstream file("resources/test1.txt");
  EXPECT_TRUE(file.is_open()) << "Error! File couldn't open";
  std::ostringstream a;
  a << file.rdbuf();
  string data = a.str();
  file.close();
  // string data = "abracadabra";

  clock_t time = SetUpClock();

  RabinKarpSearchAlgorithm r("aa5aX`aa");
  size_t out = r.search(data).size();

  TearDownClock(time);

  EXPECT_EQ(102, out);
}

TEST(RobinKarpSearch, generated_string_with_unique_hash) {
  ifstream file("resources/test2.txt");
  EXPECT_TRUE(file.is_open()) << "Error! File couldn't open";
  std::ostringstream a;
  a << file.rdbuf();
  string data = a.str();
  file.close();
  // string data = "abracadabra";

  clock_t time = SetUpClock();

  RabinKarpSearchAlgorithm r("aa5aX`aa");
  size_t out = r.search(data).size();

  TearDownClock(time);

  EXPECT_EQ(88, out);
}

TEST(RobinKarpSearch, real_text_test) {
  ifstream file("resources/test3.txt");
  EXPECT_TRUE(file.is_open()) << "Error! File couldn't open";
  std::ostringstream a;
  a << file.rdbuf();
  string data = a.str();
  file.close();
  // string data = "abracadabra";

  clock_t time = SetUpClock();

  RabinKarpSearchAlgorithm r("example");
  size_t out = r.search(data).size();

  TearDownClock(time);

  EXPECT_EQ(31, out);
}