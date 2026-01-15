#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>    

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
            std::cout << "status - displays current status of the rock" << std::endl;
            std::cout << "wisdom-c - c/c++ related wisdom" << std::endl;
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
        void status() {
            std::cout << "The current status of the rock:" << std::endl;
            std::cout << "Rock score: " << rock_score << std::endl;
            std::cout << "100 - 60 -- happy; 60 - 40 -- average; 40 - 0 -- sad" << std::endl;
            
        }
        void wisdomc() {
            int wcrng = (rand() % 3) + 1;
            switch(wcrng) {
                case 1:
                    rock_print("did you add return 0; ?", 1);
                    break;
                case 2:
                    rock_print("SEMICOLON!!!!!!!", 1);
                    break;
                case 3:
                    rock_print("don't tell anyone but gotos are actually usable", 1);
                    break;
                default:
                    break;
            }
        }
};


void readconf() {
    std::ifstream confile("ROCKCONF.cfg");
    if (!confile) {
        std::cout << "Config file not detected, creating new one named ROCKCONF.cfg" << std::endl << "If you already have one, please place it next to the executable." << std::endl;
        std::cout << "please name your rock: ";
        std::cin >> rock_name;
        
        std::ofstream newconf("ROCKCONF.cfg");
        newconf << rock_name;
        std:: cout << "config written to ROCKCONF.cfg" << std::endl;
    } else {
        std::getline(confile, rock_name);
    }
}

int command_to_id(const std::string& cmd) {
    if (cmd == "help") return 1;
    if (cmd == "quit") return 2;
    if (cmd == "wisdom") return 3;
    if (cmd == "status") return 4;
    if (cmd == "wisdom-c") return 5;
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
        case 4:
            comd.status();
            break;
        case 5:
            comd.wisdomc();
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
    readconf();
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