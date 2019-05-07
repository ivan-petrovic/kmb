#include <algorithm>    // std::shuffle
#include "engine/core/random_kmb_generator.h"
#include "engine/constants.h"


random_kmb_generator::random_kmb_generator()
: urng(rng()), dist7(0, constants::MAX7 - 1) {
    for (int i = 1; i <= constants::MAX_NUMBER; i += 1) {
        numbers.push_back(i); // 1 2 3 .. MAX_NUMBER
    }
}

kmb random_kmb_generator::generate(unsigned int n) {
    std::shuffle(numbers.begin(), numbers.end(), urng);

    kmb res;
    for(int i = 0; i < n; i += 1) {
        res.set(numbers[i]);
    }
    
    return res;
}
int random_kmb_generator::generate_index(int min, int max) {
    // return number in range [min, max]
    return std::uniform_int_distribution<>{min, max}(urng);
}

/*
using uint32 = unsigned int;

class Random {
public:
    Random() = default;
    Random(std::mt19937::result_type seed) : eng(seed) {}
    uint32 DrawNumber(uint32 min, uint32 max);

private:        
    std::mt19937 eng{std::random_device{}()};
};

uint32 Random::DrawNumber(uint32 min, uint32 max)
{
    return std::uniform_int_distribution<uint32>{min, max}(eng);
}
*/
/*
kmb random_kmb_generator::generate(unsigned int n) {
    kmb res;
    std::uniform_int_distribution<> distr(1, MAX_NUMBER); // define the range

    while (res.count() != n) {
        res.set(distr(urng));
    }
    
    return res;
}
*/

/*
#include <iostream>

int main()
{
    random_kmb_generator rngen;
    for(int i = 0; i < 10; ++i) {
        std::cout << rngen.generate() << std::endl;
    }
    return 0;
}
*/
/*
#include <iostream>
#include <random>
int main()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(25, 63); // define the range

    for(int n=0; n<40; ++n)
        std::cout << distr(eng) << ' '; // generate numbers
}
*/
