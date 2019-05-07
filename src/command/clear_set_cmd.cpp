#include <iostream>
#include "command/clear_set_cmd.h"
#include "engine/core/kmb_set_abstract.h"
#include "engine/core/kmb_set7.h"
#include "engine/core/kmb_set6.h"
#include "engine/core/kmb_set5.h"
#include "engine/core/kmb_set4.h"
#include "engine/core/kmb_set3.h"
#include "engine/core/kmb_set2.h"
#include "engine/core/kmb_set1.h"


clear_set_cmd::clear_set_cmd(std::vector<std::string> args)
: icommand(args), num(7), flag(kmb_set_abstract::EXCLUDED), flag_name("excluded") {
}

void clear_set_cmd::parse_arguments() {
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

void clear_set_cmd::execute(State & state) {
    std::cout << "clear flag " << flag_name << "... ";

    switch (num)
    {
        case 7: state.all7.clear(flag); break;
        case 6: state.all6.clear(flag); break;
        case 5: state.all5.clear(flag); break;
        case 4: state.all4.clear(flag); break;
        case 3: state.all3.clear(flag); break;
        case 2: state.all2.clear(flag); break;
        case 1: state.all1.clear(flag); break;
        default:
            std::cout << "unsuccessful.\n";
            break;
    }

    std::cout << "finished.\n";
}
