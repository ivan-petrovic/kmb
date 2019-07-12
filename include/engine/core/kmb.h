#include <iostream>
#include <vector>

#ifndef __KMB_H__
#define __KMB_H__

class kmb
{
private:
    /*
    Combination is represented with 64 bit unsigned integer.
    Position of specific bits signify whether that number
    belongs to combination.
    For example, if bits in positions 2, 5, 16 and 21
    are set, combination is 4-tuple (2, 5, 16 ,21)
    */
    unsigned long long numbers;

public:
    // constructors
    kmb();
    kmb(unsigned long long nums);

    // size of combination, that is how many numbers contains
    unsigned int count() const;

    void set(unsigned int number);
    void unset(unsigned int number);
    void toggle(unsigned int number);
    void clear();

    // checks if number belongs to combination
    bool check(unsigned int number) const;

    kmb intersection(kmb k2) const;

    void get_numbers(std::vector<unsigned char> & v);

    unsigned long long raw() const;

    bool operator<(const kmb& k) const;
};

std::ostream& operator << (std::ostream& os, kmb k);

#endif // __KMB_H__
