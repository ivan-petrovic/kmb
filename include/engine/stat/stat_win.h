#include <array>
#include "../core/kmb.h"
#include "../core/kmb_set_abstract.h"

#ifndef __STAT_WIN_H__
#define __STAT_WIN_H__

class stat_win
{
private:
    std::array<unsigned int, 8> stats;
    unsigned int total;

    std::array<int, 8> win;
    int cost1;

public:
    // constructor
    stat_win();

    void reset();
    void compute(const kmb_set_abstract & kmbs, kmb k);

    unsigned int get_total() const;
    std::array<unsigned int, 8> get_array() const;

    void print();
};

#endif // __STAT_WIN_H__ 
