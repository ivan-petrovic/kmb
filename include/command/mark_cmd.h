#include <vector>
#include <string>
#include "../state.h"
#include "icommand.h"

#ifndef __MARK_COMMAND_H__
#define __MARK_COMMAND_H__

class mark_cmd : public icommand {
private:
    int set;
    int flag;
    std::string flag_name;
public:
    mark_cmd(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __MARK_COMMAND_H__
