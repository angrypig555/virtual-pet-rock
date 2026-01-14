#include<iostream>

std::string rock_name;
int rockprompt_running = 1;
int rock_mood = 1; // 1 = happy, 2 = average, 3 = sad, 4 = angry

class rock_emotions {
    public:
        std::string happy = R"(
          _______
         /       \
        / O     O \
        \  \____/ /
         \-------/)";
};

class commands {
    public:
        void help() {
            std::cout << "virtual pet rock v1, commands" << std::endl;
            std::cout << "help - display all the commands" << std::endl;
            std::cout << "quit - exits the program" << std::endl;
        }
        void quit() {
            rockprompt_running = 0;
        }
};

void rock_print(std::string to_say) {
    std::cout << rock_name << ": " << to_say << std::endl;
}

int command_to_id(const std::string& cmd) {
    if (cmd == "help") return 1;
    if (cmd == "quit") return 2;
    return 0;
}

int execute_command(int cmd) {
    commands comd;
    switch(cmd) {
        case 1:
            comd.help();
            break;
        case 2:
            comd.quit();
            break;
        default:
            std::cout << "unknown command - see 'help' for a list of commands" << std::endl;
            break;
    }
    return 0;
}

int main() {
    rock_emotions re;
    std::cout << "virtual pet rock - its better than ai v1" << std::endl;
    std::cout << "please name your rock: (this will be later saved to a config file) ";
    std::cin >> rock_name;
    std::cout << "your pet rock is happy to see you";
    std::cout << re.happy << std::endl;
    rock_print("hi");
    std::cout << "rockprompt launched, type help for commands" << std::endl;
    while (rockprompt_running == 1) {
        std::string input;
        std::cout << "rockprompt> ";
        std::cin >> input;
        int cmd_code = command_to_id(input);
        execute_command(cmd_code);
    }
}