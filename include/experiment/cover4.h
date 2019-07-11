#include <vector>
#include <string>
#include "../state.h"
#include "../command/icommand.h"

#ifndef __COVER4_H__
#define __COVER4_H__

class cover4 : public icommand {
private:
    int num;
    int cnt;
public:
    cover4(std::vector<std::string> args);
    void parse_arguments();
    void execute(State & state);
};

#endif // __COVER4_H__
