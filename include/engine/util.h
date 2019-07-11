#include <string>
#include <vector>

#ifndef __UTIL_H__
#define __UTIL_H__

class util
{
public:
    // format int for printing,
    // for example 15380937 -> 15 380 937
    static std::string formated_int(int num);

    // split string on white spaces
    static std::vector<std::string> split(std::string const &input);
};

#endif // __UTIL_H__ 
