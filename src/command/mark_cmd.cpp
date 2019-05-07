#include "command/mark_cmd.h"
#include "state.h"
#include <iostream>


mark_cmd::mark_cmd(std::vector<std::string> args)
: icommand(args), set(7), flag(kmb_set_abstract::VISITED), flag_name("visited") {
}

void mark_cmd::parse_arguments() {
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
            if (param == "flag") {
                if (value == "excluded") {
                    flag = kmb_set_abstract::EXCLUDED;
                    flag_name = "excluded";
                } else if (value == "excluded") {
                    flag = kmb_set_abstract::VISITED;
                    flag_name = "visited";
                } else {
                    flag = kmb_set_abstract::EXCLUDED;
                    flag_name = "excluded";
                }
                std::cout << "flag (" << flag_name << "): " << flag << std::endl;
            }
        } else {
            std::cout << "invalid parameter: " << arg << '\n';
        }
    }
}

void mark_cmd::execute(State & state) {
    std::cout << "mark positions in " << set << "s set... ";

    switch (set)
    {
        case 7: state.all7.mark_positions(state.curr_kmb, flag); break;
        case 6: state.all6.mark_positions(state.curr_kmb, flag); break;
        case 5: state.all5.mark_positions(state.curr_kmb, flag); break;
        case 4: state.all4.mark_positions(state.curr_kmb, flag); break;
        case 3: state.all3.mark_positions(state.curr_kmb, flag); break;
        case 2: state.all2.mark_positions(state.curr_kmb, flag); break;
        case 1: state.all1.mark_positions(state.curr_kmb, flag); break;
        default:
            std::cout << "unsuccessful.\n";
            break;
    }

    state.result = state.positions.size();
    std::cout << "finished (" << state.result << ").\n";
}
