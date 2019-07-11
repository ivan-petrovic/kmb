#include <vector>
#include <string>
#include "../state.h"
#include "icommand.h"

#ifndef __FILTER_OUT_COMMAND_H__
#define __FILTER_OUT_COMMAND_H__

class filter_out_cmd : public icommand {
private:
    int num;
public:
    filter_out_cmd(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __FILTER_OUT_COMMAND_H__
