# Matchstick-14-28-March

The goal of this project, based on a famous Matchstick game, is to create a program that you can play against.

Every turn, each player can, on a same line, take one or several matchsticks.
The one to remove the last matchstick loses.

<img src="https://i.postimg.cc/43B4TQSv/matchstick-gameplay.png" alt="alt text">

### Linux Installer

Clone the repository:

    git clone https://github.com/MayaHill/Matchstick-14-28-March.git

To compile:

    make

Update:

    git pull && make re

## Launch the game

    ./matchstick [l] [m]
    
    l = number of lines

    m = maximum number of matches that can be taken out each turn
    
    (Example: ./matchstick 5 5)
