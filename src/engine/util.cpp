#include <vector>
#include <string>
#include <sstream>
#include "engine/util.h"

std::string util::formated_int(int num) {
    std::string numWithCommas = std::to_string(num);
    int insertPosition = numWithCommas.length() - 3;
    while (insertPosition > 0) {
        numWithCommas.insert(insertPosition, " ");
        insertPosition-=3;
    }
    return numWithCommas;
}

std::vector<std::string> util::split(std::string const &input) {
    std::istringstream buffer(input);

    std::vector<std::string> ret {
        std::istream_iterator<std::string>(buffer),
        std::istream_iterator<std::string>()
    };

    return ret;
}


/*
#include <string>
#include <iostream>
#include <iomanip>

std::string formated_int(int num);

int main() {
    std::cout << std::setw(15) << formated_int(15380937) << std::endl;
    std::cout << std::setw(15) << formated_int(6343344) << std::endl;
    std::cout << std::setw(15) << formated_int(4228896) << std::endl;
    std::cout << std::setw(15) << formated_int(1258600) << std::endl;
    std::cout << std::setw(15) << formated_int(173600) << std::endl;
    std::cout << std::setw(15) << formated_int(10416) << std::endl;
    std::cout << std::setw(15) << formated_int(224) << std::endl;
    std::cout << std::setw(15) << formated_int(1) << std::endl;
}

std::string formated_int(int num) {
    std::string numWithCommas = std::to_string(num);
    int insertPosition = numWithCommas.length() - 3;
    while (insertPosition > 0) {
        numWithCommas.insert(insertPosition, " ");
        insertPosition-=3;
    }
    return numWithCommas;
}
*/