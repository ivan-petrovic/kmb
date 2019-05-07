#include "command/check_win_cmd.h"
#include <iostream>

check_win_cmd::check_win_cmd(std::vector<std::string> args) : icommand(args) {
}

void check_win_cmd::execute(State & state) {
    std::cout << "You got " << state.curr_kmb.intersection(state.win_kmb).count() << ".\n";
}
