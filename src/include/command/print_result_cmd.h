#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __PRINT_RESULT_COMMAND_H__
#define __PRINT_RESULT_COMMAND_H__

class print_result_cmd  : public icommand {
public:
    print_result_cmd(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __PRINT_RESULT_COMMAND_H__
