#include <vector>
#include <string>
#include "../state.h"
#include "icommand.h"

#ifndef __FIND_INDEX_COMMAND_H__
#define __FIND_INDEX_COMMAND_H__

class find_index_cmd : public icommand {
private:
    int set;
public:
    find_index_cmd(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __FIND_INDEX_COMMAND_H__
