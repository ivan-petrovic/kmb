#include "engine/core/kmb_set7.h"
#include "engine/constants.h"


void kmb_set7::_init() {
    initialized = true;
    MAX = constants::MAX7;
    num = 7;
    
    kmb temp;

    kmbs.reserve(MAX);

    for (int i1 = 1; i1 <= constants::MAX_NUMBER - 6; i1 += 1)
    for (int i2 = i1 + 1; i2 <= constants::MAX_NUMBER - 5; i2 += 1)
    for (int i3 = i2 + 1; i3 <= constants::MAX_NUMBER - 4; i3 += 1)
    for (int i4 = i3 + 1; i4 <= constants::MAX_NUMBER - 3; i4 += 1)
    for (int i5 = i4 + 1; i5 <= constants::MAX_NUMBER - 2; i5 += 1)
    for (int i6 = i5 + 1; i6 <= constants::MAX_NUMBER - 1; i6 += 1)
    for (int i7 = i6 + 1; i7 <= constants::MAX_NUMBER; i7 += 1) {
        temp.clear();
        temp.set(i1);
        temp.set(i2);
        temp.set(i3);
        temp.set(i4);
        temp.set(i5);
        temp.set(i6);
        temp.set(i7);
        kmbs.push_back(temp);
    }
}
