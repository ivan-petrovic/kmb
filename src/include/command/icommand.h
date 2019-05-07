#include <vector>
#include <string>
#include "../state.h"

#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__

class icommand {
protected:
    std::vector<std::string> arguments;
public:
    icommand(std::vector<std::string> args);
    virtual void parse_arguments();
    virtual void execute(State & state);
    virtual ~icommand() = default;
};

#endif // __ICOMMAND_H__
