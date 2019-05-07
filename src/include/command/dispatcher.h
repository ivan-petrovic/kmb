#include <string>
#include "icommand.h"
#include "../state.h"

#ifndef __DISPATCHER_H__
#define __DISPATCHER_H__

class dispatcher
{
private:
    static std::unique_ptr<icommand> dispatch(std::string command);
public:
    static void execute_command(std::string command, State & state);
};

#endif // __DISPATCHER_H__ 
