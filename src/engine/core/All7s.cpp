#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <stdexcept>
#include "engine/core/All7s.h"
#include "engine/constants.h"


All7s::All7s() : mCurrentIndex(0) {
    unsigned int cnt = 0;
    kmb curr;

    mIndexes.reserve(constants::MAX7);
    mSet.reserve(constants::MAX7);
    mMap7to4s.reserve(constants::MAX7);

    // for (int i1 = 1; i1 <= 1; i1 += 1)
    for (int i1 = 1; i1 <= constants::MAX_NUMBER - 6; i1 += 1)
    for (int i2 = i1 + 1; i2 <= constants::MAX_NUMBER - 5; i2 += 1)
    for (int i3 = i2 + 1; i3 <= constants::MAX_NUMBER - 4; i3 += 1)
    for (int i4 = i3 + 1; i4 <= constants::MAX_NUMBER - 3; i4 += 1)
    for (int i5 = i4 + 1; i5 <= constants::MAX_NUMBER - 2; i5 += 1)
    for (int i6 = i5 + 1; i6 <= constants::MAX_NUMBER - 1; i6 += 1)
    for (int i7 = i6 + 1; i7 <= constants::MAX_NUMBER; i7 += 1) {
        curr.clear();
        curr.set(i1);
        curr.set(i2);
        curr.set(i3);
        curr.set(i4);
        curr.set(i5);
        curr.set(i6);
        curr.set(i7);
        mIndexes.push_back(cnt);
        mSet.push_back(curr);
        // std::vector<std::array<unsigned char,4>> all4sFromKmb;
        std::vector<kmb> all4sFromKmb;
        BreakTo4s(curr, all4sFromKmb);
        mMap7to4s.push_back(all4sFromKmb);
        cnt += 1;
    }
    mMaxSize = cnt;
    std::cout << "Ctor: cnt " << cnt << std::endl;
    std::cout << "mIndexes size: " << mIndexes.size() << std::endl;
    std::cout << "mSet size: " << mSet.size() << std::endl;
    std::cout << "mMap7to4s size: " << mMap7to4s.size() << std::endl;

}

void All7s::Shuffle() {
  // obtain a time-based seed:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  std::shuffle (mIndexes.begin(), mIndexes.end(), std::default_random_engine(seed));
}

// const std::vector<std::array<unsigned int,4>> & All7s::Get4s(kmb k) {
//     auto iter = mMap4s.find(k);
//     if (iter == mMap4s.end()) {
//         std::cout << "Get4s: not found kmb " << k << " in map of 4s.\n";
//         return std::vector<std::array<unsigned int,4>>();
//     }
//     return iter->second;
// }

// const std::vector<std::array<unsigned int,4>> & All7s::GetNext4s() {
//     unsigned int index = mIndexes[mCurrentIndex];
//     kmb k = mSet[index];

//     auto iter = mMap4s.find(k);
//     if (iter == mMap4s.end()) {
//         std::cout << "Get4s: not found kmb " << k << " in map of 4s.\n";
//         throw std::invalid_argument( "Kmb not found.");
//     }
//     mCurrentIndex += 1;
//     return iter->second;
// }

kmb All7s::GetNext() {
    unsigned int index = mIndexes[mCurrentIndex];
    return mSet[index];
}

const std::vector<kmb> & All7s::Get4s() const {
    unsigned int index = mIndexes[mCurrentIndex];
    return mMap7to4s[index];
}

bool All7s::HasNext() const {
    return mCurrentIndex < mMaxSize;
}

void All7s::Reset() {
    mCurrentIndex = 0;
}

void All7s::Advance() {
    mCurrentIndex += 1;
}

void All7s::BreakTo4s(kmb k, std::vector<std::array<unsigned char,4>> & v) {
    std::vector<unsigned char> kmbNums;
    std::array<unsigned char,4> curr4;

    k.get_numbers(kmbNums);

    for (int i1 = 0; i1 <= 3; i1 += 1)
    for (int i2 = i1 + 1; i2 <= 4; i2 += 1)
    for (int i3 = i2 + 1; i3 <= 5; i3 += 1)
    for (int i4 = i3 + 1; i4 <= 6; i4 += 1) {
        curr4[0] = kmbNums[i1];
        curr4[1] = kmbNums[i2];
        curr4[2] = kmbNums[i3];
        curr4[3] = kmbNums[i4];
        v.push_back(curr4);
    }
}

void All7s::BreakTo4s(kmb k, std::vector<kmb> & v) {
    std::vector<unsigned char> kmbNums;
    kmb curr4;

    k.get_numbers(kmbNums);

    for (int i1 = 0; i1 <= 3; i1 += 1)
    for (int i2 = i1 + 1; i2 <= 4; i2 += 1)
    for (int i3 = i2 + 1; i3 <= 5; i3 += 1)
    for (int i4 = i3 + 1; i4 <= 6; i4 += 1) {
        curr4.clear();
        curr4.set(kmbNums[i1]);
        curr4.set(kmbNums[i2]);
        curr4.set(kmbNums[i3]);
        curr4.set(kmbNums[i4]);
        v.push_back(curr4);
    }
}
