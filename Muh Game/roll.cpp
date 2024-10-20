#include "roll.h"

Roll::Roll() {

}

// Method to roll a die of a specified size
int Roll::roll(int die_size) {
    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(1, die_size);
    return dist(rng);
}