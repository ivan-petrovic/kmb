#include "command/set_win_kmb_cmd.h"
#include <iostream>

set_win_kmb_cmd::set_win_kmb_cmd(std::vector<std::string> args) : icommand(args) {
}

void set_win_kmb_cmd::execute(State & state) {
    state.win_kmb = state.curr_kmb;
    state.win_index = state.all7.find_index(state.win_kmb);
    std::cout << "win_kmb:   " << state.win_kmb << "\n";
    std::cout << "win_index: " << state.win_index << "\n";
}
