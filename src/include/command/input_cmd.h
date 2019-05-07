#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __INPUT_COMMAND_H__
#define __INPUT_COMMAND_H__

class input_cmd : public icommand {
public:
    input_cmd(std::vector<std::string> args);
    void execute(State & state);
};

#endif // __INPUT_COMMAND_H__
