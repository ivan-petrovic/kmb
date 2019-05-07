#include "command/print_cmd.h"
#include <iostream>

print_cmd::print_cmd(std::vector<std::string> args) : icommand(args) {
}

void print_cmd::execute(State & state) {
    std::cout << "Not excluded:\n";
    state.all7.print(state.win_kmb);
}
