#include "command/win_kmb_cmd.h"
#include <iostream>

win_kmb_cmd::win_kmb_cmd(std::vector<std::string> args) : icommand(args) {
}

void win_kmb_cmd::execute(State & state) {
    std::cout << "win_kmb: " << state.win_kmb << "\n";
}
