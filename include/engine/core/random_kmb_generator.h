#include <vector>       // std::vector
#include <random>       // std::random_device, std::mt19937
#include "kmb.h"

#ifndef __RANDOM_KMB_GENERATOR_H__
#define __RANDOM_KMB_GENERATOR_H__

class random_kmb_generator {
private:
    std::random_device rng;
    std::mt19937 urng;
    std::uniform_int_distribution<> dist7;
    
    std::vector<unsigned int> numbers;
public:
    random_kmb_generator();

    kmb generate(unsigned int size = 7);
    int generate_index(int min, int max);
};

#endif // __RANDOM_KMB_GENERATOR_H__
