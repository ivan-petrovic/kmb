#include "command/win_in_cmd.h"
#include <iostream>

win_in_cmd::win_in_cmd(std::vector<std::string> args) : icommand(args) {
}

void win_in_cmd::execute(State & state) {
    bool res = state.all7.check(state.win_index, kmb_set_abstract::EXCLUDED);
    std::cout << "win_kmb: " << (res ? "eliminated" : "still in pool") << "\n";
}
