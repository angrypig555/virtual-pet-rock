#include<iostream>
#include<cstdlib>
#include<ctime>

std::string rock_name;
int rockprompt_running = 1;
int rock_mood = 1; // 1 = happy, 2 = average, 3 = sad, 4 = angry
int rock_score = 100; // 100 = happy, below 60 = average below 40 = sad, angry is not here because it only lasts 2 seconds

class rock_emotions {
    public:
        std::string happy = R"(
          _______
         /       \
        / O     O \
        \  \____/ /
         \-------/)";
        std::string speaking = R"(
         _______
        /       \
       / O     O \
       \    O    /
        \-------/)";
};

void rock_print(std::string to_say, int speak) {
    rock_emotions re;
    switch(speak) {
        case 0:
            break;
        case 1:
            std::cout << re.speaking << std::endl;
            break;
        default:
            break;
    }
    std::cout << rock_name << ": " << to_say << std::endl;
}

class commands {
    public:
        void help() {
            std::cout << "virtual pet rock v1, commands" << std::endl;
            std::cout << "help - display all the commands" << std::endl;
            std::cout << "quit - exits the program" << std::endl;
            std::cout << "wisdom - get wisdom from thy rock" << std::endl;
        }
        void quit() {
            rockprompt_running = 0;
        }
        void wisdom() {
            int wrng = (rand() % 10) + 1;
            switch(wrng) {
                case 1:
                    rock_print("a person who thinks all the time has nothing to think about except thoughts", 1);
                    break;
                case 2:
                    rock_print("dont forget to say hi to gurt", 1);
                    break;
                case 3:
                    rock_print("freebsd is too mainstream", 1);
                    break;
                case 4:
                    rock_print("bogos binted?", 1);
                    break;
                case 5:
                    rock_print("you remember to terminate your printf line?", 1);
                    break;
                case 6:
                    rock_print("don't forget to renew your MOK keys", 1);
                    break;
                case 7:
                    rock_print("i heard orpheus is a good guy", 1);
                    break;
                case 8:
                    rock_print("im a rock what did you expect", 1);
                    break;
                case 9:
                    rock_print("half life 3 tomorrow", 1);
                    break;
                case 10:
                    rock_print("i dare you to compile me statically", 1);
                    break;
                default:
                    std::cout << "something went wrong in commands.wisdom, please open an issue" << std::endl;
            }
        }
};



int command_to_id(const std::string& cmd) {
    if (cmd == "help") return 1;
    if (cmd == "quit") return 2;
    if (cmd == "wisdom") return 3;
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
        case 3:
            comd.wisdom();
            break;
        default:
            std::cout << "unknown command - see 'help' for a list of commands" << std::endl;
            break;
    }
    return 0;
}

int main() {
    srand(time(0));
    rock_emotions re;
    std::cout << "virtual pet rock - its better than ai v1" << std::endl;
    std::cout << "please name your rock: (this will be later saved to a config file) ";
    std::cin >> rock_name;
    std::cout << "your pet rock is happy to see you";
    std::cout << re.happy << std::endl;
    rock_print("hi", 0);
    std::cout << "rockprompt launched, type help for commands" << std::endl;
    while (rockprompt_running == 1) {
        std::string input;
        std::cout << "rockprompt> ";
        std::cin >> input;
        int cmd_code = command_to_id(input);
        execute_command(cmd_code);
    }
}