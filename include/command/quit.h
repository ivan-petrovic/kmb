#include <vector>
#include <string>
#include "../state.h"
#include "icommand.h"

#ifndef __QUIT_COMMAND_H__
#define __QUIT_COMMAND_H__

class quit : public icommand {
public:
    quit(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __QUIT_COMMAND_H__
