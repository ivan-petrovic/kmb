// #include <cassert>
#include <iostream>
#include "engine/core/SetOf4s.h"
#include "engine/constants.h"

int main () {

    std::cout << "Start initializing set of 4s...";
    SetOf4s s4;
    std::cout << " finished initialization.\n\n";

    s4.Print();

    kmb k1;
    k1.set(1); k1.set(5); k1.set(8); k1.set(9);
    
    std::cout << "Test four kmb: " << k1 << std::endl;
    auto res = s4.CheckFlag(k1, constants::VISITED);
    if (res.second == true) {
        if (res.first == true) {
            std::cout << "Visited.\n";
        } else {
            std::cout << "Not visited.\n";
        }
    } else {
        std::cout << "Not found.\n";
    }

    std::cout << "Set " << k1 << " as visited and test.\n";
    s4.SetFlag(k1, constants::VISITED);

    res = s4.CheckFlag(k1, constants::VISITED);
    if (res.second == true) {
        if (res.first == true) {
            std::cout << "Visited.\n";
        } else {
            std::cout << "Not visited.\n";
        }
    } else {
        std::cout << "Not found.\n";
    }

    std::cout << "Test clear flags\n";
    s4.ClearFlags();
    res = s4.CheckFlag(k1, constants::VISITED);
    if (res.second == true) {
        if (res.first == true) {
            std::cout << "Visited.\n";
        } else {
            std::cout << "Not visited.\n";
        }
    } else {
        std::cout << "Not found.\n";
    }

    k1.set(11);
    std::cout << "Test five kmb: " << k1 << std::endl;
    res = s4.CheckFlag(k1, constants::VISITED);
    if (res.second == true) {
        if (res.first == true) {
            std::cout << "Visited.\n";
        } else {
            std::cout << "Not visited.\n";
        }
    } else {
        std::cout << "Not found.\n";
    }

    return 0;
}
