#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __PRINT_COMMAND_H__
#define __PRINT_COMMAND_H__

class print_cmd : public icommand {
public:
    print_cmd(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __PRINT_COMMAND_H__
