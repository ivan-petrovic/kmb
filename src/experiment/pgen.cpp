#include "command/dispatcher.h"
#include "experiment/pgen.h"
#include "state.h"
#include "engine/util.h"
#include <iostream>
#include <iomanip>
#include <numeric>      // std::partial_sum


pgen::pgen(std::vector<std::string> args)
: icommand(args), num(7), repetitions(1) {
}

void pgen::parse_arguments() {
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
*/
void pgen::execute(State & state) {
    const std::vector<kmb> & set7 = state.all7.get();
    int step = 1;

    kmb k = state.gen.generate();
    state.sw.compute(state.all7, k);

    int total = state.sw.get_total();
    std::cout << "Total: " << total << '\n';

    std::array<unsigned int, 8> input = state.sw.get_array();
    for (auto a: input) std::cout << util::formated_int(a) << '\n';

    std::array<unsigned int, 8> res;
    std::partial_sum(input.begin(), input.end(), res.begin());

    for (auto a: res) std::cout << util::formated_int(a) << '\n';
    std::cout << std::endl;

    int index = state.gen.generate_index(1, total);
    std::cout << "Generated index: " << index << '\n';

    int group = 0;
    for (int i = 0; i < 8; i += 1) {
        if (index <= res[i]) {
            group = i; break;
        }
    }

    std::cout << "Choosen group: " << group << "\n\n";

    for (int i = 0; i < set7.size(); i += 1) {
        int cnt = k.intersection(set7[i]).count();
        if (cnt == group) {
            // std::cout << "cnt: " << cnt << '\n';
            s1.add(set7[i]);
        }
        // std::cout << "Size: " << s1.get_size() << '\n';
    }
    std::cout << "Size: " << s1.get_size() << '\n';

    int cnt;
    while (cnt != 1) {
        cnt = one_step(state, step);
        if (cnt == 1 && step % 2 == 1) {
            std::cout << "S2:\n";
            for (auto el : s2.get()) {
                std::cout << el << std::endl;
            }
            std::cout << "S2 (print):\n";
            s2.print(state.win_kmb);
        } else if (cnt == 1) {
            std::cout << "S1:\n";
            for (auto el : s1.get()) {
                std::cout << el << std::endl;
            }
            std::cout << "S1 (print):\n";
            s1.print(state.win_kmb);
        }
        step += 1;
    }
}

int pgen::one_step(State & state, int step) {
    kmb k;
    state.sw.reset();
    
    if (step % 2 == 1) {
        k = s1.get()[state.gen.generate_index(0, s1.get_size() - 1)];
        state.sw.compute(s1, k);
    } else {
        k = s2.get()[state.gen.generate_index(0, s2.get_size() - 1)];
        state.sw.compute(s2, k);
    }

    int total = state.sw.get_total();
    std::cout << "Total: " << total << '\n';

    std::array<unsigned int, 8> input = state.sw.get_array();
    for (auto a: input) std::cout << util::formated_int(a) << '\n';
    std::cout << std::endl;

    std::array<unsigned int, 8> res;
    std::partial_sum(input.begin(), input.end(), res.begin());

    for (auto a: res) std::cout << util::formated_int(a) << '\n';
    std::cout << std::endl;

    int index = state.gen.generate_index(1, total);
    std::cout << "Generated index: " << index << '\n';

    int group = 0;
    for (int i = 0; i < 8; i += 1) {
        if (index <= res[i]) {
            group = i; break;
        }
    }

    std::cout << "Choosen group: " << group << "\n\n";

    int ret;
    if (step % 2 == 1) {
        s2.clear();
        for (int i = 0; i < s1.get_size(); i += 1) {
            int cnt = k.intersection(s1.get()[i]).count();
            if (cnt == group) {
                s2.add(s1.get()[i]);
            }
        }
        ret = s2.get_size();
        std::cout << "- Size: " << s2.get_size() << '\n';
    } else {
        s1.clear();
        for (int i = 0; i < s2.get_size(); i += 1) {
            int cnt = k.intersection(s2.get()[i]).count();
            if (cnt == group) {
                s1.add(s2.get()[i]);
            }
        }
        ret = s1.get_size();
        std::cout << "- Size: " << s1.get_size() << '\n';
    }
    return ret;
}
