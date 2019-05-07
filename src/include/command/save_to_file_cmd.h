#include <vector>
#include <string>
#include "state.h"
#include "icommand.h"

#ifndef __SAVE_TO_FILE_COMMAND_H__
#define __SAVE_TO_FILE_COMMAND_H__

class save_to_file_cmd : public icommand {
    std::string file_name;
public:
    save_to_file_cmd(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __SAVE_TO_FILE_COMMAND_H__
