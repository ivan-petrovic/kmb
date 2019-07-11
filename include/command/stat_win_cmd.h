#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __STAT_WIN_COMMAND_H__
#define __STAT_WIN_COMMAND_H__

class stat_win_cmd : public icommand {
public:
    stat_win_cmd(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __STAT_WIN_COMMAND_H__
