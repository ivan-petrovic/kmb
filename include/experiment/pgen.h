#include <vector>
#include <string>
#include "../state.h"
#include "../command/icommand.h"

#ifndef __PGEN_H__
#define __PGEN_H__

class pgen : public icommand {
private:
    int num;
    int repetitions;

    kmb_set_abstract s1;
    kmb_set_abstract s2;

    int one_step(State & state, int step);
public:
    pgen(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __PGEN_H__
