
rockname = "rock"

def rock_happy_show():
    rock_happy = r"""
        _______
       /       \
      / O     O \
      \  \____/ /
       \-------/"""
    print(rock_happy)

def rock_print(rock):
    print(rockname + ": " + rock)


running = True
print("virtual pet rock - its better than ai v1")
print("please name your rock: (this will be later saved to a config file)")
rockname = input()

rock_happy_show()
print("your pet rock is happy to see you")
rock_print("hi")

while running == True:
    running = False # placeholder