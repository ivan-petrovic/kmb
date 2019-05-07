#include "engine/constants.h"

const unsigned int constants::MAX_NUMBER = 39;

const unsigned int constants::MAX1 = MAX_NUMBER;

const unsigned int constants::MAX2 = MAX1 * (MAX_NUMBER - 1) / 2;

const unsigned int constants::MAX3 = MAX2 * (MAX_NUMBER - 2) / 3;

const unsigned int constants::MAX4 = MAX3 * (MAX_NUMBER - 3) / 4;

const unsigned int constants::MAX5 = MAX4 * (MAX_NUMBER - 4) / 5;

const unsigned int constants::MAX6 = MAX5 * (MAX_NUMBER - 5) / 6;

const unsigned int constants::MAX7 = MAX6 * (MAX_NUMBER - 6) / 7;

/*
#include <iostream>

int main() {
    std::cout << "MAX_NUMBER: " << constants::MAX_NUMBER << std::endl;
    std::cout << "MAX1: " << constants::MAX1 << std::endl;
    std::cout << "MAX2: " << constants::MAX2 << std::endl;
    std::cout << "MAX3: " << constants::MAX3 << std::endl;
    std::cout << "MAX4: " << constants::MAX4 << std::endl;
    std::cout << "MAX5: " << constants::MAX5 << std::endl;
    std::cout << "MAX6: " << constants::MAX6 << std::endl;
    std::cout << "MAX7: " << constants::MAX7 << std::endl;
}
*/