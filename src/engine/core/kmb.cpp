#include <iostream>
#include <iomanip>
#include "engine/core/kmb.h"
#include "engine/constants.h"

kmb::kmb() : numbers(0ULL) {
}

kmb::kmb(unsigned long long nums) : numbers(nums) {
}

/*
Function to get no of set bits in binary
representation of passed binary no.

Subtraction of 1 from a number toggles all the bits (from right to left)
till the rightmost set bit (including the rightmost set bit).
So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)),
we unset the rightmost set bit.

If we do n & (n-1) in a loop and count the no of times loop executes
we get the set bit count.
The beauty of this solution is the number of times it loops is equal
to the number of set bits in a given integer.

1 Initialize count: = 0
2 If integer n is not zero
    (a) Do bitwise & with (n-1) and assign the value back to n
        n: = n&(n-1)
    (b) Increment count by 1
    (c) go to step 2
3 Else return count
*/
unsigned int kmb::count() const {
    unsigned int cnt = 0;
    unsigned long long n = numbers;

    while (n) {
        n &= (n-1);
        cnt += 1;
    }
    
    return cnt;
}

void kmb::set(unsigned int number) {
    numbers |= 1ULL << number;
}

void kmb::unset(unsigned int number) {
    numbers &= ~(1ULL << number);
}

void kmb::toggle(unsigned int number) {
    numbers ^= 1ULL << number;
}

void kmb::clear() {
    numbers = 0ULL;
}

bool kmb::check(unsigned int number) const {
    unsigned long long bit = (numbers >> number) & 1ULL;
    return bit > 0;
}

kmb kmb::intersection(kmb k2) const {
    return kmb(numbers & k2.numbers);
}

unsigned long long kmb::raw() const {
    return numbers;
}

bool kmb::operator<(const kmb& k) const {
    return numbers < k.numbers;
}
void kmb::get_numbers(std::vector<unsigned char> & v) {
    for (unsigned char i = 0; i <= constants::MAX_NUMBER; i += 1) {
        if(check(i)) v.push_back(i);
    }
}

std::ostream& operator << (std::ostream& os, kmb k) {
    for (int i = 0; i <= constants::MAX_NUMBER; i += 1) {
        if(k.check(i)) os << std::setw(3) << i;
    }
    return os;
}

/*
int main()
{
    kmb k1(9);
    k1.set(10);
    k1.toggle(21);
   
    std::cout << "Kmb1: " << k1 << std::endl;
    std::cout << "k1.raw: " << k1.raw() << std::endl;
    std::cout << "k1.count(): " << k1.count() << std::endl;
    if (k1.check(20))
        std::cout << "20th bit set" << std::endl;
    else
        std::cout << "20th bit not set" << std::endl;
    if (k1.check(21)) std::cout << "21th bit set" << std::endl;
    
    kmb k2(9);
    std::cout << "Kmb2: " << k2 << std::endl;
    std::cout << "k1.intersection(k2).count: " << k1.intersection(k2).count() << std::endl;
    std::cout << "Intersection Kmb1 and Kmb2: " << k1.intersection(k2) << std::endl;
    std::cout << "Intersection Kmb2 and Kmb1: " << k2.intersection(k1) << std::endl;
    std::cout << "Intersection Kmb1 and Kmb1: " << k1.intersection(k1) << std::endl;

    int input;
    std::cout << "Input number: ";
    std::cin >> input;

    kmb k3(input);
    std::cout << "Kmb3: " << k3 << std::endl;
    
    return 0;
}
*/