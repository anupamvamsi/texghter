#include "Random.hpp"

#include <random>

int GenerateRandomNum(int low_lim, int up_lim) {
  // non-deterministic generator
  std::random_device rand_dev;

  // gen() generates random nums in undefined ranges
  std::mt19937 gen(rand_dev());

  // dist(gen()) generates random nums in a range
  std::uniform_int_distribution<int> dist(low_lim, up_lim);

  int rand_num = dist(gen);

  return rand_num;
}

float GenerateRandomNum(double low_lim, double up_lim) {
  std::random_device rand_dev;
  std::mt19937 gen(rand_dev());

  std::uniform_real_distribution<double> dist(low_lim, up_lim);
  float rand_num = dist(gen);

  return rand_num;
}