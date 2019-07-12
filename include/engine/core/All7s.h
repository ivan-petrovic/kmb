#include <array>
#include <vector>
#include "kmb.h"

#ifndef __ALL_7S_H__
#define __ALL_7S_H__

class All7s
{
public:
    All7s();

    void Shuffle();
    // const std::vector<std::array<unsigned int,4>> & Get4s(kmb k);
    // const std::vector<std::array<unsigned int,4>> & GetNext4s();
    kmb GetNext();
    void BreakTo4s(kmb k, std::vector<std::array<unsigned char,4>> & v);
    void BreakTo4s(kmb k, std::vector<kmb> & v);
    const std::vector<kmb> & Get4s() const;
    bool HasNext() const;
    void Reset();
    void Advance();

protected:
    std::vector<unsigned int> mIndexes;
    std::vector<kmb> mSet;
    // std::vector<std::vector<std::array<unsigned char,4>>> mMap7to4s;
    std::vector<std::vector<kmb>> mMap7to4s;

    unsigned int mMaxSize;
    unsigned int mCurrentIndex;
};

#endif // __ALL_7S_H__ 
