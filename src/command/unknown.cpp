#include "command/unknown.h"

unknown::unknown(std::vector<std::string> args) : icommand(args) {
}

void unknown::execute(State & state) {
    std::cout << "\nUnknown command: " << arguments[0] << std::endl;
}
