#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __WIN_IN_COMMAND_H__
#define __WIN_IN_COMMAND_H__

class win_in_cmd : public icommand {
public:
    win_in_cmd(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __WIN_IN_COMMAND_H__
