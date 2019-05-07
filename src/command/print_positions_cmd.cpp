#include "command/print_positions_cmd.h"
#include <iostream>

print_positions_cmd::print_positions_cmd(std::vector<std::string> args) : icommand(args) {
}

void print_positions_cmd::execute(State & state) {
    for(int i = 0; i < state.positions.size(); i += 1) {
        std::cout << state.positions[i] << "; ";
    }
    std::cout << '\n';
}
