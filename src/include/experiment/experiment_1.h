#include <vector>
#include <string>
#include "../state.h"
#include "../command/icommand.h"

#ifndef __EXPERIMENT_1_H__
#define __EXPERIMENT_1_H__

class experiment_1 : public icommand {
private:
    int num;
    int repetitions;
public:
    experiment_1(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __EXPERIMENT_1_H__
