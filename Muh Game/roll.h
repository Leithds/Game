#pragma once

#include <random>
#include <ctime>

class Roll {
public:
    Roll();

    // Method to roll a die of a specified size
    int roll(int die_size);
};