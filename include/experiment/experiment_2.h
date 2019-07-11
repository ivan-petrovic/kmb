#include <vector>
#include <string>
#include "../state.h"
#include "../command/icommand.h"

#ifndef __EXPERIMENT_2_H__
#define __EXPERIMENT_2_H__

class experiment_2 : public icommand {
private:
    int num;
    int cnt;
public:
    experiment_2(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __EXPERIMENT_2_H__
