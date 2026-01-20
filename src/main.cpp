#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>    

std::string rock_name;
int rockprompt_running = 1;
int rock_mood = 1; // 1 = happy, 2 = average, 3 = sad, 4 = angry
int rock_score = 100; // 100 = happy, below 60 = average below 40 = sad, angry is not here because it only lasts 2 seconds
int hunger;
int cycle;
int anger;

class rock_emotions {
    public: // this class contains all of the ascii art in raw format for the rock, pasted from ascii-art/ascii_art.txt
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
        std::string angry = R"(
         _______
        / \   / \
       / O     O \
       \    O    /
        \-------/)";
};

void rock_print(std::string to_say, int speak) {
    rock_emotions re; // this is a function for printing with the rock, speak 1 = rock_speaking speak 2 = happy_rock, everything other no rock
    switch(speak) {
        case 0:
            break;
        case 1:
            std::cout << re.speaking << std::endl;
            break;
        case 2:
            std::cout << re.happy << std::endl;
            break;
        case 3:
            std::cout << re.angry << std::endl;
            break;
        default:
            break;
    }
    std::cout << rock_name << ": " << to_say << std::endl;
}

class commands {
    public:
        void help() { // help command, prints all the commands
            std::cout << "virtual pet rock v1, commands" << std::endl;
            std::cout << "help - display all the commands" << std::endl;
            std::cout << "quit - exits the program" << std::endl;
            std::cout << "wisdom - get wisdom from thy rock" << std::endl;
            std::cout << "status - displays current status of the rock" << std::endl;
            std::cout << "wisdom-c - c/c++ related wisdom" << std::endl;
            std::cout << "wisdom-py - python related wisdom" << std::endl;
            std::cout << "feed - feed the rock rock food" << std::endl;
            std::cout << "insult - insult the rock, why would you do that" << std::endl;
        }
        void quit() {
            rock_print("see ya later", 0);
            rockprompt_running = 0;
        }
        void wisdom() { // every wisdom command prints wisdom with an rng and a switch case
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
                    rock_print("did you remember to terminate your printf line?", 1);
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
            std::cout << "Hunger: " << hunger << std::endl;
            std::cout << "100 - very hungry, 0 - not hungry" << std::endl;
            std::cout << "Anger: " << anger << std::endl;
            std::cout << "If it reaches 100, you are in deep trouble. Can only go down by feeding." << std::endl;
            
        }
        void feed() {
            if (hunger > 0 and hunger <= 100) { // this checks if the rock is hungry, 0 meaning not hungry 100 meaning very hungry
                hunger -= 25;
                anger -= 25;
                rock_print("yummy!", 2);
                if (rock_score < 100) {
                    rock_score += 10;
                }
            } else {
                rock_print("im not hungry", 1);
            }
        }
        void wisdomc() {
            int wcrng = (rand() % 4) + 1;
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
                case 4:
                    rock_print("did you use gcc on a c++ program?", 1);
                    break;
                default:
                    break;
            }
        }
        void wisdompy() {
            int pyrng = (rand() % 5) + 1;
            switch(pyrng) {
                case 1:
                    rock_print("don't worry, it works on my machine", 1);
                    break;
                case 2:
                    rock_print("no, its a feature that the user has to set up a venv", 1);
                    break;
                case 3:
                    rock_print("oops, you need an older version of python for this library", 1);
                    break;
                case 4:
                    rock_print("do not pip --break-system-packages", 1);
                    break;
                case 5:
                    rock_print("but it worked on my machine", 1);
                    break;
                default:
                    break;

            }
        }
        void insult() {
          anger += 25;
          rock_score -= 10;
          if (anger >= 100) {
            rock_print("THATS IT IM LEAVING", 3);
            rockprompt_running = 0;
          }
          int irng = (rand() % 5) + 1;
          switch(irng) {
            case 1:
                rock_print("nuh uh", 3);
                break;
            case 2:
                rock_print("im telling ur parents", 3);
                break;
            case 3:
                rock_print("weak insult", 3);
                break;
            case 4:
                rock_print("better scramble like an egg before you get folded like an omlette", 3);
                break;
            case 5:
                rock_print("why", 3);
                break;
            default:
                break;
          }
        }
};


void readconf() { // this function reads and creates the config
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
    if (cmd == "help") return 1; // this handles commands
    if (cmd == "quit") return 2;
    if (cmd == "wisdom") return 3;
    if (cmd == "status") return 4;
    if (cmd == "wisdom-c") return 5;
    if (cmd == "feed") return 6;
    if (cmd == "wisdom-py") return 7;
    if (cmd == "insult") return 8;
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
        case 6:
            comd.feed();
            break;
        case 7:
            comd.wisdompy();
            break;
        case 8:
            comd.insult();
            break;
        default:
            std::cout << "unknown command - see 'help' for a list of commands" << std::endl;
            break;
    }
    return 0;
}

void comp_cycles() { // everything that runs in a cycle goes here like the random wisdom and hunger logic
    if (cycle == 5 and hunger >= 0 and hunger < 100) {
        hunger += 10;
        cycle = 0;
        int cycrng = (rand() % 2) + 1;
        switch(cycrng) {
            case 1:
                execute_command(3);
                break;
            default:
                break;
        }
        
    }
    if (hunger == 100) {
        rock_print("please feed me :(", 1);
        rock_score -= 10;
    }
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
    while (rockprompt_running == 1) { // main loop
        std::string input;
        std::cout << "rockprompt> ";
        std::cin >> input;
        int cmd_code = command_to_id(input);
        execute_command(cmd_code);
        cycle += 1;
        comp_cycles();
    }
    
}
