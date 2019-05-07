#include "command/print_result_cmd.h"
#include <iostream>

print_result_cmd::print_result_cmd(std::vector<std::string> args) : icommand(args) {
}

void print_result_cmd::execute(State & state) {
    std::cout << "result: " << state.result << "\n";
}
