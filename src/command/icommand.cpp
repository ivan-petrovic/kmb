#include "command/icommand.h"

icommand::icommand(std::vector<std::string> args) {
    arguments = args;
}

void icommand::parse_arguments() {
}

void icommand::execute(State & state) {
}
