#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __CLEAR_SET_COMMAND_H__
#define __CLEAR_SET_COMMAND_H__

class clear_set_cmd  : public icommand {
private:
    int num;
    int flag;
    std::string flag_name;
public:
    clear_set_cmd(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __CLEAR_SET_COMMAND_H__
