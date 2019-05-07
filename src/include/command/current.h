#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __CURRENT_COMMAND_H__
#define __CURRENT_COMMAND_H__

class current : public icommand {
public:
    current(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __CURRENT_COMMAND_H__
