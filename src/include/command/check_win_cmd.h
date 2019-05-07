#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __CHECK_WIN_COMMAND_H__
#define __CHECK_WIN_COMMAND_H__

class check_win_cmd : public icommand {
public:
    check_win_cmd(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __CHECK_WIN_COMMAND_H__
