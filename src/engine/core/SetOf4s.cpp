#include <iostream>
#include "engine/core/SetOf4s.h"
#include "engine/constants.h"


SetOf4s::SetOf4s() {
    unsigned int allZeros = 0;
    kmb curr;

    mSet.reserve(constants::MAX4);

    for (int i1 = 1; i1 <= constants::MAX_NUMBER - 3; i1 += 1)
    for (int i2 = i1 + 1; i2 <= constants::MAX_NUMBER - 2; i2 += 1)
    for (int i3 = i2 + 1; i3 <= constants::MAX_NUMBER - 1; i3 += 1)
    for (int i4 = i3 + 1; i4 <= constants::MAX_NUMBER; i4 += 1) {
        // build combination
        curr.clear();
        curr.set(i1);
        curr.set(i2);
        curr.set(i3);
        curr.set(i4);
        
        mSet.push_back(curr);
        auto iter = mMap.insert({curr, allZeros});
    }
}

void SetOf4s::SetFlag(kmb k, unsigned int flag) {
    auto iter = mMap.find(k);
    if (iter == mMap.end()) {
        std::cout << "SetFlag: no kmb " << k << " in map of 4s.\n";
    }
    iter->second |= 1 << flag;
}

std::pair<bool, bool> SetOf4s::CheckFlag(kmb k, unsigned int flag) const {
    auto iter = mMap.find(k);
    if (iter == mMap.end()) {
        // std::cout << "CheckFlag: no kmb " << k << " in map of 4s.\n";
        return std::make_pair(0, false);
    }
    return std::make_pair((iter->second >> flag) & 1, true);
}

void SetOf4s::ClearFlags() {
    for (auto &  x : mMap) {
        x.second = 0;
    }
}

unsigned int SetOf4s::CountFlags(unsigned int flag) const {
    unsigned int cnt = 0;
    for (auto const &  x : mMap) {
        if ((x.second >> flag) & 1) cnt += 1;
    }
    return cnt;
}

void SetOf4s::Print() {

    std::cout << "Stats for set of 4s\n";
    std::cout << "-------------------\n";
    
    std::cout << "Max number of flags: " << sizeof(unsigned int) * 8 << std::endl;
    std::cout << "Set contains: " << mSet.size() << " 4s in " << sizeof(kmb) * mSet.size() << " bytes.\n";
    std::cout << "Map contains: " << mMap.size() << " 4s.\n\n";
}
