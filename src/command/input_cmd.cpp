#include "command/input_cmd.h"
#include <iostream>

input_cmd::input_cmd(std::vector<std::string> args) : icommand(args) {
}

void input_cmd::execute(State & state) {
    int i1, i2, i3, i4, i5, i6, i7;
    std::cout << "Input kmb (7 numbers): ";
    std::cin >> i1 >> i2 >> i3 >> i4 >> i5 >> i6 >> i7;
    std::cin.ignore();
    
    kmb temp;
    temp.set(i1); temp.set(i2); temp.set(i3); temp.set(i4);
    temp.set(i5); temp.set(i6); temp.set(i7);

    state.curr_kmb = temp;
}
