// #include <cassert>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "engine/core/SetOf4s.h"
#include "engine/core/All7s.h"
#include "engine/constants.h"

bool Count(const std::vector<kmb> & kmbs7to4s, SetOf4s & s4, int num, int maxnum);
bool Count1(const std::vector<kmb> & kmbs7to4s, SetOf4s & s4, int num, int maxnum);

int main () {

    std::cout << "Start initializing set of 4s...";
    SetOf4s s4;
    std::cout << " finished.\n\n";
    
    std::cout << "Start initializing set of all 7s...\n";
    All7s s7;
    std::cout << "finished.\n\n";

    // kmb k1;
    // k1.set(1); k1.set(5); k1.set(7); k1.set(14); k1.set(18); k1.set(26); k1.set(37);

    // std::cout << "Fours of " << k1 << std::endl;
    // std::vector<std::array<unsigned int,4>> all4sFromKmb;
    // s7.BreakTo4s(k1, all4sFromKmb);
    // for(int i = 0; i < all4sFromKmb.size(); i += 1) {
    //     std::cout << std::setw(3) << i+1 << ": ";
    //     std::cout
    //         << std::setw(3) << all4sFromKmb[i][0]
    //         << std::setw(3) << all4sFromKmb[i][1]
    //         << std::setw(3) << all4sFromKmb[i][2]
    //         << std::setw(3) << all4sFromKmb[i][3] << "\n";
    // }

    // std::cout << "Fours of " << k1 << " another way\n";
    // std::vector<kmb> all4sFromKmb1;
    // s7.BreakTo4s(k1, all4sFromKmb1);
    // for(int i = 0; i < all4sFromKmb1.size(); i += 1) {
    //     std::cout << std::setw(3) << i+1 << ": ";
    //     std::cout << all4sFromKmb1[i] << "\n";
    // }

    // std::cout << "Shuffling... ";
    // s7.Shuffle();
    // std::cout << "finished.\n\n";
    unsigned int totalKmbs = 0;
    for (int j = 35; j > 0; j -= 1) {
        unsigned int c = 0;
        unsigned int nFound = 0;

        s7.Reset();
        while(s7.HasNext()) {
            kmb k = s7.GetNext();
            
            // std::vector<kmb> all4sFromKmb;
            // s7.BreakTo4s(k, all4sFromKmb);
            const std::vector<kmb> & all4sFromKmb = s7.Get4s();
            
            if( Count(all4sFromKmb, s4, j, 35)) {
                nFound += 1;
                // std::cout << std::setw(10) << c << " (" << std::setw(8) << nFound << "): " << k << std::endl;
            };

            s7.Advance();
            
            c += 1;
        }
        std::cout << "Total found with " << std::setw(2) << j << ": " << std::setw(5) << nFound << " kmbs (" << c << ").\n";
        unsigned int totalVisited = s4.CountFlags(constants::VISITED);
        totalKmbs += nFound;
        std::cout << "With total of " << totalKmbs << " kmbs, visited 4s: " << totalVisited << std::endl;
        if (totalVisited == constants::MAX4) break;
    }

    // std::cout << "Shuffling... ";
    // s7.Shuffle();
    // std::cout << "finished.\n\n";
    // // for (int j = 35; j > 19; j -= 1) {
    //     unsigned int c = 0;
    //     unsigned int nFound = 0;

    //     s7.Reset();
    //     for(int index = 0; index < 2000; ++index) {
    //         kmb k = s7.GetNext();
            
    //         std::vector<kmb> all4sFromKmb;
    //         s7.BreakTo4s(k, all4sFromKmb);
            
    //         if( Count1(all4sFromKmb, s4, 10, 35)) {
    //             nFound += 1;
    //             std::cout << std::setw(10) << c << " (" << std::setw(8) << nFound << "): " << k << std::endl;
    //         };
            
    //         c += 1;
    //     }
    //     std::cout << "Total found with " << std::setw(2) << 1 << ": " << std::setw(5) << nFound << " kmbs (" << c << ").\n";
    //     // std::cout << "Total found with " << std::setw(2) << j << ": " << std::setw(5) << nFound << " kmbs (" << c << ").\n";
    //     std::cout << "Total visited 4s: " << s4.CountFlags(constants::VISITED) << std::endl;
    // // }
    return 0;
}

bool Count(const std::vector<kmb> & kmbs7to4s, SetOf4s & s4, int num, int maxnum) {
    int allowedMiss = maxnum - num;
    int currAllowedMiss = 0;
    int currFound = 0;

    for(int i = 0; i < kmbs7to4s.size(); i += 1) {
        auto res = s4.CheckFlag(kmbs7to4s[i], constants::VISITED);
        if (res.second == true) {
            if (res.first == true) {
                // std::cout << "Visited.\n";
                currAllowedMiss += 1;
            } else {
                // std::cout << "Not visited.\n";
                currFound += 1;
            }
        } else {
            throw std::invalid_argument( "Kmb not found.");
        }

        if (currAllowedMiss > allowedMiss) return false;
    }

    if (currFound > num) {
        std::cout << "FOUND GREATER: " << currFound << " of " << num << std::endl;
    }

    if (currFound == num) {
        for(int i = 0; i < kmbs7to4s.size(); i += 1) {
            s4.SetFlag(kmbs7to4s[i], constants::VISITED);
        }
        return true;
    }
    
    std::cout << "Should not get here.\n";
    return false;
}

bool Count1(const std::vector<kmb> & kmbs7to4s, SetOf4s & s4, int num, int maxnum) {
    int allowedMiss = maxnum - num;
    int currAllowedMiss = 0;
    int currFound = 0;

    for(int i = 0; i < kmbs7to4s.size(); i += 1) {
        auto res = s4.CheckFlag(kmbs7to4s[i], constants::VISITED);
        if (res.second == true) {
            if (res.first == true) {
                // std::cout << "Visited.\n";
                currAllowedMiss += 1;
            } else {
                // std::cout << "Not visited.\n";
                currFound += 1;
            }
        } else {
            throw std::invalid_argument( "Kmb not found.");
        }

        if (currAllowedMiss > allowedMiss) return false;
    }

    if (currFound >= num) {
        for(int i = 0; i < kmbs7to4s.size(); i += 1) {
            s4.SetFlag(kmbs7to4s[i], constants::VISITED);
        }
        return true;
    }
    
    std::cout << "Should not get here.\n";
    return false;
}
