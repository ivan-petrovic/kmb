#include <vector>
#include <string>
#include "../state.h"
#include "icommand.h"

#ifndef __GENERATE_COMMAND_H__
#define __GENERATE_COMMAND_H__

class generate : public icommand {
private:
    int num;
public:
    generate(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __GENERATE_COMMAND_H__
