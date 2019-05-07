#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __WIN_KMB_COMMAND_H__
#define __WIN_KMB_COMMAND_H__

class win_kmb_cmd : public icommand {
public:
    win_kmb_cmd(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __WIN_KMB_COMMAND_H__
