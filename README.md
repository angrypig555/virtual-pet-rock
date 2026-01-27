![hackatime](https://hackatime-badge.hackclub.com/U09U824EK3P/virtual-pet-rock)
# 🪨 virtual-pet-rock
Virtual pet rock is your cli buddy.
It can tell you wisdom, you can feed it, you can anger him and more!
It may even tell you coding advice!

# 🎯 Features
- Wisdom in multiple programming languages
- Hunger
- Anger
- Randomly telling wisdom
- Tracking your favourite wisdom

## 🔨 How to build?
To build this project, you need cmake and a compiler of your source.
To compile it run ./build.sh.
An AUR release may be released soon.

## 🪟 How to build for windows?
It is possible but not reccomended to build for windows.
You need to have the mingw-w64-gcc compiler installled and run ./winbuild.sh
Compiling is only possible from a linux machine.

## 🐛 KNOWN BUGS
- Currently, the config system is broken on windows. It is caused by the 2 different systems using different methods to create files.

If you would like to report a bug, please open an issue.

## ⚙️ Config
All configurations are saved to a file called ROCKCONFIG.cfg
If there isn't one already next to the executable, the program will create its own.

### 🤖 AI?
Very little AI was used in this project, mainly for debugging. No big chunks of code were written with AI.
