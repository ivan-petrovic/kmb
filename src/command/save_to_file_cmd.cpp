#include "command/save_to_file_cmd.h"
#include <iostream>

save_to_file_cmd::save_to_file_cmd(std::vector<std::string> args)
: icommand(args), file_name("temp.txt") {
}

void save_to_file_cmd::parse_arguments() {
    for(int i = 1; i < arguments.size(); i += 1) {
        std::string arg = arguments[i];

        std::size_t found = arg.find("=");
        if (found != std::string::npos) {
            std::string param = arg.substr(0, found);
            std::string value = arg.substr(found + 1);
            std::cout << "param name:  " << param << '\n';
            std::cout << "param value: " << value << '\n';

            if (param == "file") {
                try {
                    file_name = value;
                } catch (...) {
                    file_name = "temp.txt";
                }
                std::cout << "file_name: " << file_name << std::endl;
            }
        } else {
            std::cout << "invalid parameter: " << arg << '\n';
        }
    }
}

void save_to_file_cmd::execute(State & state) {
    state.save1.save(file_name);
}
