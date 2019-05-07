#include <iostream>
#include <iomanip>
#include <vector>
#include "engine/stat/stat_win.h"
#include "engine/util.h"


stat_win::stat_win() : cost1(1)
{
    win = {0, 0, 0, 1, 10, 70, 1000, 100000};
    reset();
}

void stat_win::reset() {
    total = 0;
    for(int i = 0; i < 8; i += 1) {
        stats[i] = 0;
    }
}

void stat_win::compute(const kmb_set_abstract & kmbs, kmb k) {
    reset();

    const std::vector<kmb> & v = kmbs.get();

    for (unsigned int i = 0; i < kmbs.get_size(); i += 1) {
        if (v[i].check(kmb_set_abstract::EXCLUDED)) {
            continue;
        }
        stats[k.intersection(v[i]).count()] += 1;
        total += 1;
    }
}

void stat_win::print() {
    for(int i = 0; i < 8; i += 1) {
        std::cout << i << ": " << std::setw(15) << util::formated_int(stats[i]);
        std::cout << " [" << std::fixed << std::setprecision(4)
            << (float)stats[i] * 100 / total << "]\n";
    }
    std::cout << "total: " << std::setw(15) << util::formated_int(total) << "\n\n";
    int total_cost = total * cost1;

    int sum = 0;
    for(int i = 3; i < 8; i += 1) {
        int win_amount = stats[i] * win[i];
        sum += win_amount;

        std::cout << i << ": " << std::setw(15) << util::formated_int(win_amount) << '\n';
    }
    std::cout << "------------------\n";
    std::cout << "win:  " << std::setw(15) << util::formated_int(sum) << std::endl;
    std::cout << "cost: " << std::setw(15) << util::formated_int(total_cost) << std::endl;
    std::cout << "------------------\n";
    std::cout << "total:  " << std::setw(15) << util::formated_int(sum - total_cost) << std::endl;
}

unsigned int stat_win::get_total() const {
    return total;
}

std::array<unsigned int, 8> stat_win::get_array() const {
    return stats;
}
