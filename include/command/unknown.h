#include <vector>
#include <string>
#include "../state.h"
#include "icommand.h"

#ifndef __UNKNOWN_COMMAND_H__
#define __UNKNOWN_COMMAND_H__

class unknown : public icommand {
public:
    unknown(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __UNKNOWN_COMMAND_H__
