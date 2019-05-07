#include "engine/core/kmb_set2.h"
#include "engine/constants.h"

void kmb_set2::_init() {
    initialized = true;
    MAX = constants::MAX2;
    num = 2;
    
    kmb temp;

    kmbs.reserve(MAX);

    for (int i1 = 1; i1 <= constants::MAX_NUMBER - 1; i1 += 1)
    for (int i2 = i1 + 1; i2 <= constants::MAX_NUMBER; i2 += 1) {
        temp.clear();
        temp.set(i1);
        temp.set(i2);
        kmbs.push_back(temp);
    }
}
