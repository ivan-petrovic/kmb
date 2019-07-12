#include <vector>
#include <map>
#include "kmb.h"

#ifndef __SET_OF_4S_H__
#define __SET_OF_4S_H__

class SetOf4s
{
public:
    SetOf4s();

    void SetFlag(kmb k, unsigned int flag);
    std::pair<bool, bool> CheckFlag(kmb k, unsigned int flag) const;
    
    void ClearFlags();
    unsigned int CountFlags(unsigned int flag) const;
    void Print();

    // std::pair<int, bool> GetFlags(kmb k) const;

protected:
    std::vector<kmb> mSet;
    std::map<kmb, unsigned int> mMap;
};

#endif // __SET_OF_4S_H__ 
