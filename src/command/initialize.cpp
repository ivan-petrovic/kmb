#include <iostream>
#include "command/initialize.h"
#include "engine/core/kmb_set_abstract.h"
#include "engine/core/kmb_set7.h"
#include "engine/core/kmb_set6.h"
#include "engine/core/kmb_set5.h"
#include "engine/core/kmb_set4.h"
#include "engine/core/kmb_set3.h"
#include "engine/core/kmb_set2.h"
#include "engine/core/kmb_set1.h"


initialize::initialize(std::vector<std::string> args) : icommand(args), num(7) {
}

void initialize::parse_arguments() {
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

void initialize::execute(State & state) {
    std::cout << "init all " << num << "s set...";
    int size = 0;

    switch (num)
    {
        case 7: state.all7.init(); size = state.all7.get_size(); break;
        case 6: state.all6.init(); size = state.all6.get_size(); break;
        case 5: state.all5.init(); size = state.all5.get_size(); break;
        case 4: state.all4.init(); size = state.all4.get_size(); break;
        case 3: state.all3.init(); size = state.all3.get_size(); break;
        case 2: state.all2.init(); size = state.all2.get_size(); break;
        case 1: state.all1.init(); size = state.all1.get_size(); break;
        default:
            std::cout << "unsuccessful.\n";
            break;
    }

    std::cout << "finished (" << size << ").\n";
}
