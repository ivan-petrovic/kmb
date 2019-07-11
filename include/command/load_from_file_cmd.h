#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __LOAD_FROM_FILE_COMMAND_H__
#define __LOAD_FROM_FILE_COMMAND_H__

class load_from_file_cmd : public icommand {
    std::string file_name;
public:
    load_from_file_cmd(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __LOAD_FROM_FILE_COMMAND_H__
