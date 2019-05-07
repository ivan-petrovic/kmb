#include "engine/core/kmb_set3.h"
#include "engine/constants.h"


void kmb_set3::_init() {
    initialized = true;
    MAX = constants::MAX3;
    num = 3;
    
    kmb temp;

    kmbs.reserve(MAX);

    for (int i1 = 1; i1 <= constants::MAX_NUMBER - 2; i1 += 1)
    for (int i2 = i1 + 1; i2 <= constants::MAX_NUMBER - 1; i2 += 1)
    for (int i3 = i2 + 1; i3 <= constants::MAX_NUMBER; i3 += 1) {
        temp.clear();
        temp.set(i1);
        temp.set(i2);
        temp.set(i3);
        kmbs.push_back(temp);
    }
}
