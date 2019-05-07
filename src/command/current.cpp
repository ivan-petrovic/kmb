#include "command/current.h"
#include <iostream>

current::current(std::vector<std::string> args) : icommand(args) {
}

void current::execute(State & state) {
    std::cout << "curr_kmb: " << state.curr_kmb << "\n";
}
