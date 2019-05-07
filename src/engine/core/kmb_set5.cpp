#include "engine/core/kmb_set5.h"
#include "engine/constants.h"


void kmb_set5::_init() {
    initialized = true;
    MAX = constants::MAX5;
    num = 5;
    
    kmb temp;

    kmbs.reserve(MAX);

    for (int i1 = 1; i1 <= constants::MAX_NUMBER - 4; i1 += 1)
    for (int i2 = i1 + 1; i2 <= constants::MAX_NUMBER - 3; i2 += 1)
    for (int i3 = i2 + 1; i3 <= constants::MAX_NUMBER - 2; i3 += 1)
    for (int i4 = i3 + 1; i4 <= constants::MAX_NUMBER - 1; i4 += 1)
    for (int i5 = i4 + 1; i5 <= constants::MAX_NUMBER; i5 += 1) {
        temp.clear();
        temp.set(i1);
        temp.set(i2);
        temp.set(i3);
        temp.set(i4);
        temp.set(i5);
        kmbs.push_back(temp);
    }
}
