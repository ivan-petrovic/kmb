#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __PRINT_POSITIONS_COMMAND_H__
#define __PRINT_POSITIONS_COMMAND_H__

class print_positions_cmd  : public icommand {
public:
    print_positions_cmd(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __PRINT_POSITIONS_COMMAND_H__
