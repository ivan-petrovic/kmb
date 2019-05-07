#include "command/find_index_cmd.h"
#include "state.h"
#include <iostream>


find_index_cmd::find_index_cmd(std::vector<std::string> args) : icommand(args), set(7) {
}

void find_index_cmd::parse_arguments() {
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

void find_index_cmd::execute(State & state) {
        int index;
        int num = state.curr_kmb.count();
        switch (num)
        {
            case 7: index = state.all7.find_index(state.curr_kmb); break;
            case 6: index = state.all6.find_index(state.curr_kmb); break;
            case 5: index = state.all5.find_index(state.curr_kmb); break;
            case 4: index = state.all4.find_index(state.curr_kmb); break;    
            case 3: index = state.all3.find_index(state.curr_kmb); break;    
            case 2: index = state.all2.find_index(state.curr_kmb); break;    
            case 1: index = state.all1.find_index(state.curr_kmb); break;    
            default: index = -1; break;
        }
        state.curr_index = index;

        std::cout << "find index in " << num << "s set... ";
        std::cout << "finished (" << index << ").\n";
}
