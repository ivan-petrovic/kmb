#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __INITIALIZE_COMMAND_H__
#define __INITIALIZE_COMMAND_H__

class initialize  : public icommand {
private:
    int num;
public:
    initialize(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __INITIALIZE_COMMAND_H__
