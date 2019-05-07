#include <iostream>
#include <string>
#include <memory>

#include "command/dispatcher.h"
#include "command/icommand.h"

#include "state.h"


int main() {
    State state;
    std::string command;
    
    std::cout << "KMB v0.1 | Mangan, Inc.\n";
    std::cout << "Use q or quit for exit\n";

    state.keep_running = true;
    do {
        std::cout << "> ";
        std::getline (std::cin, command);
        
        dispatcher::execute_command(command, state);

    } while (state.keep_running);

    std::cout << "Bye.\n";
    return 0;
}
