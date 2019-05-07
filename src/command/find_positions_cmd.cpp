#include "command/find_positions_cmd.h"
#include "state.h"
#include <iostream>


find_positions_cmd::find_positions_cmd(std::vector<std::string> args) : icommand(args), set(7) {
}

void find_positions_cmd::parse_arguments() {
    for(int i = 1; i < arguments.size(); i += 1) {
        std::string arg = arguments[i];

        std::size_t found = arg.find("=");
        if (found != std::string::npos) {
            std::string param = arg.substr(0, found);
            std::string value = arg.substr(found + 1);
            std::cout << "param name:  " << param << '\n';
            std::cout << "param value: " << value << '\n';

            if (param == "set") {
                try {
                    set = std::stoi(value);
                } catch (...) {
                    set = 0;
                }
                std::cout << "set: " << set << std::endl;
            }
        } else {
            std::cout << "invalid parameter: " << arg << '\n';
        }
    }
}

void find_positions_cmd::execute(State & state) {
    std::cout << "count positions in " << set << "s set... ";

    switch (set)
    {
        case 6: state.positions = state.all6.find_positions(state.curr_kmb); break;
        case 5: state.positions = state.all5.find_positions(state.curr_kmb); break;
        case 4: state.positions = state.all4.find_positions(state.curr_kmb); break;
        case 3: state.positions = state.all3.find_positions(state.curr_kmb); break;
        case 2: state.positions = state.all2.find_positions(state.curr_kmb); break;
        case 1: state.positions = state.all1.find_positions(state.curr_kmb); break;
        default:
            std::cout << "unsuccessful.\n";
            break;
    }

    state.result = state.positions.size();
    std::cout << "finished (" << state.result << ").\n";
}
