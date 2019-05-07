#include "engine/core/kmb_set1.h"
#include "engine/constants.h"

void kmb_set1::_init() {
    initialized = true;
    MAX = constants::MAX_NUMBER;
    num = 1;
    
    kmb temp;

    kmbs.reserve(MAX);

    for (int i1 = 1; i1 <= constants::MAX_NUMBER; i1 += 1) {
        temp.clear();
        temp.set(i1);
        kmbs.push_back(temp);
    }
}
