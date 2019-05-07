#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __SAVE_KMB_COMMAND_H__
#define __SAVE_KMB_COMMAND_H__

class save_kmb_cmd : public icommand {
    int slot;
public:
    save_kmb_cmd(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __SAVE_KMB_COMMAND_H__
