#include "command/save_kmb_cmd.h"
#include <iostream>

save_kmb_cmd::save_kmb_cmd(std::vector<std::string> args) : icommand(args), slot(1) {
}

void save_kmb_cmd::parse_arguments() {
    for(int i = 1; i < arguments.size(); i += 1) {
        std::string arg = arguments[i];

        std::size_t found = arg.find("=");
        if (found != std::string::npos) {
            std::string param = arg.substr(0, found);
            std::string value = arg.substr(found + 1);
            std::cout << "param name:  " << param << '\n';
            std::cout << "param value: " << value << '\n';

            if (param == "slot") {
                try {
                    slot = std::stoi(value);
                } catch (...) {
                    slot = 1;
                }
                std::cout << "slot: " << slot << std::endl;
            }
        } else {
            std::cout << "invalid parameter: " << arg << '\n';
        }
    }
}

void save_kmb_cmd::execute(State & state) {
    state.save1.add(state.curr_kmb);
}
