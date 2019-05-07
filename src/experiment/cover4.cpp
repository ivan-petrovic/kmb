#include "command/dispatcher.h"
#include "experiment/cover4.h"
#include "state.h"
#include <iostream>


cover4::cover4(std::vector<std::string> args)
: icommand(args), num(7), cnt(5) {
}

void cover4::parse_arguments() {
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
void cover4::execute(State & state) {
    std::vector<kmb> result_set;
    int init_search_count = 35;  // 1(7) -> 35(4)
    int curr_search_count ;
    float coverage = 0.0;
    float coverage_limit = 50.0;
    int covered_cnt = 0;
    int generate_limit = 50000;
    int max4 = state.all4.get_size();

    for (
        curr_search_count = init_search_count;
        curr_search_count > 0;
        curr_search_count -= 1
    ) {
        int generated_cnt = 0;
        bool exit_calculation = false;
        int found = 0;
        int not_found = 0;
        
        std::cout << "curr_search_count: " << curr_search_count << '\n';
        
        while (generated_cnt < generate_limit) {
            kmb temp = state.gen.generate();
            generated_cnt += 1;
            
            if (generated_cnt % 2500 == 0) {
                std::cout << "generated_cnt: " << generated_cnt << '\n';                
            }
            // std::vector<int> positions = state.all4.count_positions(temp);
            std::vector<int> positions = state.all4.find_unvisited_positions(temp);
            int n = positions.size();

            if (n == curr_search_count) {
                found += 1;
                state.all4.mark_positions(positions);
                result_set.push_back(temp);
                covered_cnt += curr_search_count;
                coverage = float(covered_cnt) * 100 / max4;
                if (coverage > coverage_limit) {
                    exit_calculation = true;
                }
            } else {
                not_found += 1;
            }
            if (exit_calculation) break;
        }

        std::cout << "generated_cnt: " << generated_cnt << '\n';
        std::cout << "found     (" << found << ")\n";
        std::cout << "not found (" << not_found << ")\n";

        if (exit_calculation) {
            break;
            std::cout << "exit\n";
        }
    }

    std::cout << "\nSummary:\n";
    std::cout << "curr_search_count: " << curr_search_count << '\n';
    std::cout << "covered_cnt: " << covered_cnt << '\n';
    std::cout << "coverage: " << coverage << '\n';
    std::cout << "result_set size: " << result_set.size() << '\n';
    // state.save1 = result_set;
    // dispatcher::execute_command("stat_win", state);
}
