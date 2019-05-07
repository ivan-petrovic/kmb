#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __SET_WIN_KMB_COMMAND_H__
#define __SET_WIN_KMB_COMMAND_H__

class set_win_kmb_cmd : public icommand {
public:
    set_win_kmb_cmd(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __SET_WIN_KMB_COMMAND_H__
