#include "command/dispatcher.h"
#include "experiment/experiment_1.h"
#include "state.h"
#include <iostream>


experiment_1::experiment_1(std::vector<std::string> args)
: icommand(args), num(7), repetitions(1) {
}

void experiment_1::parse_arguments() {
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
            if (param == "rep") {
                try {
                    repetitions = std::stoi(value);
                } catch (...) {
                    repetitions = 0;
                }
                std::cout << "repetitions: " << repetitions << std::endl;
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
void experiment_1::execute(State & state) {
   
    for(int i = 0; i < repetitions; i += 1) {
        state.curr_kmb = state.gen.generate(num);   // dispatcher::execute_command("gen num=5", state);
        state.all7.filter_out(state.curr_kmb, num);
    }

    dispatcher::execute_command("stat_win", state);
}

/*
Prerequisits:
    dispatcher::execute_command("init num=7", state);
    dispatcher::execute_command("init num=5", state);
    dispatcher::execute_command("gen num=7", state);
    dispatcher::execute_command("set_win", state);
*/

/*
void experiment_1::execute(State & state) {

    
    for(int i = 0; i < repetitions; i += 1) {
        state.curr_kmb = state.gen.generate(num);   // dispatcher::execute_command("gen num=5", state);
    }

    state.curr_kmb = state.gen.generate(num);
    dispatcher::execute_command("find_index set=5", state);

    std::cout << "index: " << state.curr_index << std::endl;

    int begin_index = state.curr_index - 1000;
    if (begin_index < 0) begin_index = 0;
    int end_index = state.curr_index;
    
    for(int i = begin_index; i < end_index; i += 1) {
        if (i % 100 == 0) std::cout << i << std::endl;
        state.all7.filter_out(i, state.all5, 5);
    }

    dispatcher::execute_command("stat_win", state);
}
*/