#include <string>
#include <vector>
#include <memory>

#include "command/dispatcher.h"
#include "engine/util.h"

// list of commands:
#include "command/icommand.h"
#include "command/generate.h"
#include "command/initialize.h"
#include "command/current.h"
#include "command/input_cmd.h"
#include "command/win_kmb_cmd.h"
#include "command/set_win_kmb_cmd.h"
#include "command/win_in_cmd.h"
#include "command/check_win_cmd.h"
#include "command/filter_out_cmd.h"
#include "command/mark_cmd.h"
#include "command/find_positions_cmd.h"
#include "command/clear_set_cmd.h"
#include "command/find_index_cmd.h"
#include "command/stat_win_cmd.h"
#include "command/print_result_cmd.h"
#include "command/print_positions_cmd.h"
#include "command/print_cmd.h"
#include "command/save_kmb_cmd.h"
#include "command/save_to_file_cmd.h"
#include "command/load_from_file_cmd.h"
#include "command/unknown.h"
#include "command/quit.h"

// list of experiments
#include "experiment/experiment_1.h"
#include "experiment/experiment_2.h"
#include "experiment/cover4.h"
#include "experiment/pgen.h"


std::unique_ptr<icommand> dispatcher::dispatch(std::string command) {
    std::vector<std::string> args = util::split(command);
    std::string cmd_name = args[0];

    if (cmd_name == "q" || cmd_name == "quit") {
        return std::unique_ptr<icommand>{new quit(args)};
    
    } else if (cmd_name == "gen") {
        return std::unique_ptr<icommand>{new generate(args)};

    } else if (cmd_name == "init") {
        return std::unique_ptr<icommand>{new initialize(args)};

    } else if (cmd_name == "curr") {
        return std::unique_ptr<icommand>{new current(args)};

    } else if (cmd_name == "input") {
        return std::unique_ptr<icommand>{new input_cmd(args)};

    } else if (cmd_name == "win") {
        return std::unique_ptr<icommand>{new win_kmb_cmd(args)};

    } else if (cmd_name == "set_win") {
        return std::unique_ptr<icommand>{new set_win_kmb_cmd(args)};

    } else if (cmd_name == "win_in") {
        return std::unique_ptr<icommand>{new win_in_cmd(args)};

    } else if (cmd_name == "check_win") {
        return std::unique_ptr<icommand>{new check_win_cmd(args)};

    } else if (cmd_name == "filter_out") {
        return std::unique_ptr<icommand>{new filter_out_cmd(args)};

    } else if (cmd_name == "mark") {
        return std::unique_ptr<icommand>{new mark_cmd(args)};

    } else if (cmd_name == "find_positions") {
        return std::unique_ptr<icommand>{new find_positions_cmd(args)};

    } else if (cmd_name == "clear_set") {
        return std::unique_ptr<icommand>{new clear_set_cmd(args)};

    } else if (cmd_name == "find_index") {
        return std::unique_ptr<icommand>{new find_index_cmd(args)};

    } else if (cmd_name == "stat_win") {
        return std::unique_ptr<icommand>{new stat_win_cmd(args)};

    } else if (cmd_name == "print_result") {
        return std::unique_ptr<icommand>{new print_result_cmd(args)};

    } else if (cmd_name == "print_positions") {
        return std::unique_ptr<icommand>{new print_positions_cmd(args)};

    } else if (cmd_name == "print") {
        return std::unique_ptr<icommand>{new print_cmd(args)};

    } else if (cmd_name == "save_kmb") {
        return std::unique_ptr<icommand>{new save_kmb_cmd(args)};

    } else if (cmd_name == "save_to_file") {
        return std::unique_ptr<icommand>{new save_to_file_cmd(args)};

    } else if (cmd_name == "load_from_file") {
        return std::unique_ptr<icommand>{new load_from_file_cmd(args)};

    } else if (cmd_name == "e1") {
        return std::unique_ptr<icommand>{new experiment_1(args)};

    } else if (cmd_name == "e2") {
        return std::unique_ptr<icommand>{new experiment_2(args)};

    } else if (cmd_name == "cover4") {
        return std::unique_ptr<icommand>{new cover4(args)};

    } else if (cmd_name == "pgen") {
        return std::unique_ptr<icommand>{new pgen(args)};

    } else {
        return std::unique_ptr<icommand>{new unknown(args)};
    }
}

void dispatcher::execute_command(std::string command, State & state) {
    std::unique_ptr<icommand> p_cmd = dispatcher::dispatch(command);
    p_cmd->parse_arguments();
    p_cmd->execute(state);
}
