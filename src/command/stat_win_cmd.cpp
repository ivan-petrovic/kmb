#include "command/stat_win_cmd.h"
#include <iostream>

stat_win_cmd::stat_win_cmd(std::vector<std::string> args) : icommand(args) {
}

void stat_win_cmd::execute(State & state) {
    state.sw.compute(state.all7, state.win_kmb);
    state.sw.print();
}
