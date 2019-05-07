#include "command/quit.h"

quit::quit(std::vector<std::string> args) : icommand(args) {
}

void quit::execute(State & state) {
    state.keep_running = false;
}
