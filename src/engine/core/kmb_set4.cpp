#include "engine/core/kmb_set4.h"
#include "engine/constants.h"


void kmb_set4::_init() {
    initialized = true;
    MAX = constants::MAX4;
    num = 4;
    
    kmb temp;

    kmbs.reserve(MAX);

    for (int i1 = 1; i1 <= constants::MAX_NUMBER - 3; i1 += 1)
    for (int i2 = i1 + 1; i2 <= constants::MAX_NUMBER - 2; i2 += 1)
    for (int i3 = i2 + 1; i3 <= constants::MAX_NUMBER - 1; i3 += 1)
    for (int i4 = i3 + 1; i4 <= constants::MAX_NUMBER; i4 += 1) {
        temp.clear();
        temp.set(i1);
        temp.set(i2);
        temp.set(i3);
        temp.set(i4);
        kmbs.push_back(temp);
    }
}
