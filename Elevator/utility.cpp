#include "utility.h"
#include <random>

int uniform_int(int x) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, x);

    int random_number = dist(gen);

    return random_number;
  }
