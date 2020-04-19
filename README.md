# OmokGame
This is a desktop application of the game Omok which is a variation of the game Gomoku. It is a connect 5 tic-tac-toe game on a 15x15 grid. It has 2 rules: 
1. Overline: You cannot win if you connect 6 or more. it must be connect 5 to win.
2. Double three: You cannot move in a spot where you create two open threes at once. An open three follows the patterns: OXXXO, OXXOX, or OXOXX.
## Requirements
1. Windows 10 operating system
2. Qt Creator 4.11.1 (Community)
3. Qt 5.9.9

You can download Qt using this link: https://www.qt.io/download.

## How to Run
1. Download the zip file of the code from GitHub.
2. Open up Qt Creator.
3. Go to File -> Open File or Project -> Select the Omok.pro file
4. Click the green run button or press Ctrl-R to run the program
5. Wait for the application to build and run
6. Play Omok. You start first.
7. If you want to play again, you have to close the application and press run again.

### Or if you do not want to download Qt to build and run the program:
1. Go to https://www.dropbox.com/sh/vabputybywy2af8/AACuOTQJ8IwJWDw0Ay3S-QwMa?dl=0. (I'm using Dropbox because the dll files were too big to upload onto GitHub.)
2. Download the Omok folder which holds the Omok.exe and all its dependencies.
3. Open the Omok folder.
4. Run the game through Omok.exe.

## File Descriptions
1. Omok.pro - project file. Specifies the what Qt libraries, configuration language, source code, header files, and target path are used.
2. main.cpp - source file. Has main function which starts the application, calls Board, and displays Board on the application.
3. board.h - header file. Holds the declarations of the Board class and most of the libraries used.
4. board.cpp - source file. Has all the Board functions and constructor. It can generate the board with all its buttons, check for valid moves when the button is clicked, check for the 2 rules, and pick the computer's move with the AI which checks for certain patterns.
