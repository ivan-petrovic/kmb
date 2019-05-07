#include "command/generate.h"
#include "state.h"
#include "engine/core/random_kmb_generator.h"
#include <iostream>


generate::generate(std::vector<std::string> args) : icommand(args), num(7) {
}

void generate::parse_arguments() {
    for(int i = 1; i < arguments.size(); i += 1) {
        std::string arg = arguments[i];

        std::size_t found = arg.find("=");
        if (found != std::string::npos) {
            std::string param = arg.substr(0, found);
            std::string value = arg.substr(found + 1);
            std::cout << "param name:  " << param << '\n';
            std::cout << "param value: " << value << '\n';

            if (param == "num") {
                try {
                    num = std::stoi(value);
                } catch (...) {
                    num = 0;
                }
                std::cout << "num: " << num << std::endl;
            }
        } else {
            std::cout << "invalid parameter: " << arg << '\n';
        }
    }
}

void generate::execute(State & state) {
    state.curr_kmb = state.gen.generate(num);
}
