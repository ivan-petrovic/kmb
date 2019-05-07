#include "command/dispatcher.h"
#include "experiment/experiment_2.h"
#include "state.h"
#include <iostream>


experiment_2::experiment_2(std::vector<std::string> args)
: icommand(args), num(7), cnt(5) {
}

void experiment_2::parse_arguments() {
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
            if (param == "cnt") {
                try {
                    cnt = std::stoi(value);
                } catch (...) {
                    cnt = 0;
                }
                std::cout << "cnt: " << cnt << std::endl;
            }
        } else {
            std::cout << "invalid parameter: " << arg << '\n';
        }
    }
}

/*
Prerequisits:
    dispatcher::execute_command("init num=7", state);
    dispatcher::execute_command("gen num=7", state);
    dispatcher::execute_command("set_win", state);
*/
void experiment_2::execute(State & state) {
    int cnt_left = 15380937;
    int prev_cnt_left = cnt_left;
    int repetition = 0;
    int MAX_REPETITION = 10;

    while (repetition != MAX_REPETITION) {
        state.curr_kmb = state.gen.generate(num);
        cnt_left = state.all7.filter_out(state.curr_kmb, cnt);

        std::cout << "prev_cnt: " << prev_cnt_left << '\n';
        std::cout << "cnt: " << cnt_left << '\n';

        if (cnt_left == prev_cnt_left) {
            repetition += 1;
        } else {
            repetition = 0;
        }
        prev_cnt_left = cnt_left;
        
        std::cout << "repetition: " << repetition << '\n';
    }
    
    dispatcher::execute_command("stat_win", state);
}
