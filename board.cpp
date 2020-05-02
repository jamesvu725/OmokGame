#include "board.h"

// set up the grid layout to display the board
Board::Board(QWidget *parent) : QWidget(parent) {
    QGridLayout *gridLayout = new QGridLayout;
    createButtons(gridLayout);
    createGrid();
    createPatterns();
    setLayout(gridLayout);
}

// create buttons for board
void Board::createButtons(QGridLayout *gridLayout) {
    QString buttonText = "";
    const QSize BUTTON_SIZE = QSize(40,40);
    // creates all the buttons, adds it to the vector, set the size, connect the signals, and place it on the grid
    for (int i = 0; i < 225; ++i) {
        QPushButton *button = new QPushButton(buttonText);
        buttons.append(button);
        button->setFixedSize(BUTTON_SIZE);
        connect(button, &QPushButton::clicked, [=] { buttonClicked(i); });
        gridLayout->addWidget(button, i / 15, i % 15);
    }
}

// adds patterns to vector
void Board::createPatterns() {
    open3.append({0,1,1,1,0});
    open3.append({0,1,1,0,1,0});
    open3.append({0,1,0,1,1,0});
    // winning move
    patterns.append({3,2,2,2,2,   16384});
    patterns.append({2,3,2,2,2,   16384});
    patterns.append({2,2,3,2,2,   16384});
    patterns.append({2,2,2,3,2,   16384});
    patterns.append({2,2,2,2,3,   16384});
    // block win
    patterns.append({3,1,1,1,1,   8192});
    patterns.append({1,3,1,1,1,   8192});
    patterns.append({1,1,3,1,1,   8192});
    patterns.append({1,1,1,3,1,   8192});
    patterns.append({1,1,1,1,3,   8192});
    // create open 4
    patterns.append({0,3,2,2,2,0, 2048});
    patterns.append({0,2,3,2,2,0, 2048});
    patterns.append({0,2,2,3,2,0, 2048});
    patterns.append({0,2,2,2,3,0, 2048});
    // block open 4
    patterns.append({0,3,1,1,1,0, 1024});
    patterns.append({0,1,3,1,1,0, 1024});
    patterns.append({0,1,1,3,1,0, 1024});
    patterns.append({0,1,1,1,3,0, 1024});
    // create open 3
    patterns.append({0,0,3,2,2,0, 256});
    patterns.append({0,0,2,3,2,0, 256});
    patterns.append({0,0,2,2,3,0, 256});
    patterns.append({0,3,2,2,0,0, 256});
    patterns.append({0,2,3,2,0,0, 256});
    patterns.append({0,2,2,3,0,0, 256});
    patterns.append({0,3,0,2,2,0, 256});
    patterns.append({0,2,0,3,2,0, 256});
    patterns.append({0,2,0,2,3,0, 256});
    patterns.append({0,3,2,0,2,0, 256});
    patterns.append({0,2,3,0,2,0, 256});
    patterns.append({0,2,2,0,3,0, 256});
    // block open 3
    patterns.append({0,0,3,1,1,0, 128});
    patterns.append({0,0,1,3,1,0, 128});
    patterns.append({0,0,1,1,3,0, 128});
    patterns.append({0,3,1,1,0,0, 128});
    patterns.append({0,1,3,1,0,0, 128});
    patterns.append({0,1,1,3,0,0, 128});
    patterns.append({0,3,0,1,1,0, 128});
    patterns.append({0,1,0,3,1,0, 128});
    patterns.append({0,1,0,1,3,0, 128});
    patterns.append({0,3,1,0,1,0, 128});
    patterns.append({0,1,3,0,1,0, 128});
    patterns.append({0,1,1,0,3,0, 128});
    // create 3
    patterns.append({2,2,3,0,0,   32});
    patterns.append({2,2,0,3,0,   32});
    patterns.append({2,2,0,0,3,   32});
    patterns.append({2,3,2,0,0,   32});
    patterns.append({2,0,2,3,0,   32});
    patterns.append({2,0,2,0,3,   32});
    patterns.append({2,3,0,2,0,   32});
    patterns.append({2,0,3,2,0,   32});
    patterns.append({2,0,0,2,3,   32});
    patterns.append({2,3,0,0,2,   32});
    patterns.append({2,0,3,0,2,   32});
    patterns.append({2,0,0,3,2,   32});
    patterns.append({3,2,2,0,0,   32});
    patterns.append({0,2,2,3,0,   32});
    patterns.append({0,2,2,0,3,   32});
    patterns.append({3,2,0,2,0,   32});
    patterns.append({0,2,3,2,0,   32});
    patterns.append({0,2,0,2,3,   32});
    patterns.append({3,2,0,0,2,   32});
    patterns.append({0,2,3,0,2,   32});
    patterns.append({0,2,0,3,2,   32});
    patterns.append({3,0,2,2,0,   32});
    patterns.append({0,3,2,2,0,   32});
    patterns.append({0,0,2,2,3,   32});
    patterns.append({3,0,2,0,2,   32});
    patterns.append({0,3,2,0,2,   32});
    patterns.append({0,0,2,3,2,   32});

    // block 3
    patterns.append({1,1,3,0,0,   16});
    patterns.append({1,1,0,3,0,   16});
    patterns.append({1,1,0,0,3,   16});
    patterns.append({1,3,1,0,0,   16});
    patterns.append({1,0,1,3,0,   16});
    patterns.append({1,0,1,0,3,   16});
    patterns.append({1,3,0,1,0,   16});
    patterns.append({1,0,3,1,0,   16});
    patterns.append({1,0,0,1,3,   16});
    patterns.append({1,3,0,0,1,   16});
    patterns.append({1,0,3,0,1,   16});
    patterns.append({1,0,0,3,1,   16});
    patterns.append({3,1,1,0,0,   16});
    patterns.append({0,1,1,3,0,   16});
    patterns.append({0,1,1,0,3,   16});
    patterns.append({3,1,0,1,0,   16});
    patterns.append({0,1,3,1,0,   16});
    patterns.append({0,1,0,1,3,   16});
    patterns.append({3,1,0,0,1,   16});
    patterns.append({0,1,3,0,1,   16});
    patterns.append({0,1,0,3,1,   16});
    patterns.append({3,0,1,1,0,   16});
    patterns.append({0,3,1,1,0,   16});
    patterns.append({0,0,1,1,3,   16});
    patterns.append({3,0,1,0,1,   16});
    patterns.append({0,3,1,0,1,   16});
    patterns.append({0,0,1,3,1,   16});

    // create 2
    patterns.append({2,3,0,0,0,   4});
    patterns.append({2,0,3,0,0,   4});
    patterns.append({2,0,0,3,0,   4});
    patterns.append({2,0,0,0,3,   4});
    patterns.append({3,2,0,0,0,   4});
    patterns.append({0,2,3,0,0,   8});
    patterns.append({0,2,0,3,0,   8});
    patterns.append({0,2,0,0,3,   4});
    patterns.append({3,0,2,0,0,   4});
    patterns.append({0,3,2,0,0,   8});
    patterns.append({0,0,2,3,0,   8});
    patterns.append({0,0,2,0,3,   4});
    patterns.append({3,0,0,2,0,   4});
    patterns.append({0,3,0,2,0,   8});
    patterns.append({0,0,3,2,0,   8});
    patterns.append({0,0,0,2,3,   4});
    patterns.append({3,0,0,0,2,   4});
    patterns.append({0,3,0,0,2,   4});
    patterns.append({0,0,3,0,2,   4});
    patterns.append({0,0,0,3,2,   4});
    patterns.append({2,0,0,3,     3});
    patterns.append({2,0,3,       2});
    patterns.append({2,3,         1});
    patterns.append({3,0,0,0,2,   4});
    patterns.append({3,0,0,2,     3});
    patterns.append({3,0,2,       2});
    patterns.append({3,2,         1});
    // block 2
    patterns.append({1,3,0,0,0,   4});
    patterns.append({1,0,3,0,0,   4});
    patterns.append({1,0,0,3,0,   4});
    patterns.append({1,0,0,0,3,   4});
    patterns.append({3,1,0,0,0,   4});
    patterns.append({0,1,3,0,0,   8});
    patterns.append({0,1,0,3,0,   8});
    patterns.append({0,1,0,0,3,   4});
    patterns.append({3,0,1,0,0,   4});
    patterns.append({0,3,1,0,0,   8});
    patterns.append({0,0,1,3,0,   8});
    patterns.append({0,0,1,0,3,   4});
    patterns.append({3,0,0,1,0,   4});
    patterns.append({0,3,0,1,0,   8});
    patterns.append({0,0,3,1,0,   8});
    patterns.append({0,0,0,1,3,   4});
    patterns.append({3,0,0,0,1,   4});
    patterns.append({0,3,0,0,1,   4});
    patterns.append({0,0,3,0,1,   4});
    patterns.append({0,0,0,3,1,   4});
    patterns.append({1,0,0,3,     3});
    patterns.append({1,0,3,       2});
    patterns.append({1,3,         1});
    patterns.append({3,0,0,0,1,   4});
    patterns.append({3,0,0,1,     3});
    patterns.append({3,0,1,       2});
    patterns.append({3,1,         1});
}

// create grid to store states of buttons
void Board::createGrid() {
    QVector<int> inner(15);
    inner.fill(0);
    for (int i = 0; i < 15; ++i) {
        grid.push_back(inner);
        weightGrid.push_back((inner));
    }
}

// updates state of the grid
void Board::updateGrid(int id, int state) {
    grid[id/15][id%15] = state;
}

// resets weightGrid to 0
void Board::resetWeightGrid() {
    QVector<int> inner(15);
    inner.fill(0);
    weightGrid.fill(inner);
}

// marks player's button if valid
void Board::buttonClicked(int id) {
    // checks for valid move
    if (checkValidMove(id)) {
        if (playerTurn) { // sets text to X for player and updates grid
            buttons[id]->setText("X");
            changeBackground(id/15,id%15,"cyan");
            updateGrid(id, 1);
        } else { // sets text to O for player and and updates grid
            buttons[id]->setText("O");
            changeBackground(id/15,id%15,"red");
            updateGrid(id, 2);
        }
        // if win, then finish game
        if (checkFive()) {
            if (playerTurn) {
                QMessageBox::information(this, "Congrats", "Congratulation on winning.");
            } else {
                QMessageBox::information(this, "Game Over", "The computer AI won.");
            }
        } else { // switches player
            if (playerTurn) {
                playerTurn = false;
                int computerChoice = computerAI();
                // AI chooses its move
                if (computerChoice != -1) { buttonClicked(computerChoice); }
            } else {
                playerTurn = true;
            }
        }
    }
}

// checks if button is filled or double threes
bool Board::checkValidMove(int id) {
    // check if button is empty
    if (checkButtonFill(id)) {
        if (playerTurn) {
            QMessageBox::warning(this, "Warning", "Invalid move. Button is already occupied. Please click on another button.");
        }
        return false;
    }
    // if double threes found, return false
    if (checkDoubleThrees(id)) {
        if (playerTurn) {
            QMessageBox::warning(this, "Warning", "Invalid move. Violates double three rule. Please click on another button.");
        }
        return false;
    }
    // returns true if there is no double threes and space is available
    return true;
}

// returns true if state is not 0
bool Board::checkButtonFill(int id) {
    return grid[id/15][id%15] != 0;
}

// checks for any connect 5 without overline
bool Board::checkFive() {
    if (checkFiveHori())  { return true; }
    if (checkFiveVert())  { return true; }
    if (checkFiveDiag1()) { return true; }
    if (checkFiveDiag2()) { return true; }
    return false;
}

// checks for connect 5 horizontally
bool Board::checkFiveHori() {
    bool flag = true;
    int player = 0;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            // checks if grid spot is not empty
            if (grid[i][j] != 0) {
                player = grid[i][j];
                // checks if next 4 spots matches the first
                for (int k = 1; k < 5; ++k) {
                    if (grid[i][j+k] != player) {
                        flag = false;
                        break;
                    }
                }
                // check for overline
                if (j - 1 >= 0 && flag) {
                    if (grid[i][j-1] == player) { flag = false; }
                }
                if (j + 5 <= 14 && flag) {
                    if (grid[i][j+5] == player) { flag = false; }
                }
                // returns true if 5 in a row with no overline
                if (flag) {
                    for (int k = 0; k < 5; ++k) {
                        changeBackground(i, j+k, "yellow");
                    }
                    return true;
                }
                flag = true;
            }
        }
    }
    // returns false if no connect 5
    return false;
}

// checks for connect 5 vertically
bool Board::checkFiveVert() {
    int player = 0;
    bool flag = true;
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 15; ++j) {
            // checks if grid spot is not empty
            if (grid[i][j] != 0) {
                player = grid[i][j];
                // checks if next 4 spots matches the first
                for (int k = 1; k < 5; ++k) {
                    if (grid[i+k][j] != player) {
                        flag = false;
                        break;
                    }
                }
                // check for overline
                if (i - 1 >= 0 && flag) {
                    if (grid[i-1][j] == player) { flag = false; }
                }
                if (i + 5 <= 14 && flag) {
                    if (grid[i+5][j] == player) { flag = false; }
                }
                // returns true if 5 in a row with no overline
                if (flag) {
                    for (int k = 0; k < 5; ++k) {
                        changeBackground(i+k, j, "yellow");
                    }
                    return true;
                }
                flag = true;
            }
        }
    }
    // returns false if no connect 5
    return false;
}

// checks for connect 5 diagonally top left to bottom right
bool Board::checkFiveDiag1() {
    int player = 0;
    bool flag = true;
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            // checks if grid spot is not empty
            if (grid[i][j] != 0) {
                player = grid[i][j];
                // checks if next 4 spots matches the first
                for (int k = 1; k < 5; ++k) {
                    if (grid[i+k][j+k] != player) {
                        flag = false;
                        break;
                    }
                }
                // check for overline
                if (i - 1 >= 0 && j - 1 >= 0 && flag) {
                    if (grid[i-1][j-1] == player) { flag = false; }
                }
                if (i + 5 <= 14 && j + 5 <= 14 && flag) {
                    if (grid[i+5][j+5] == player) { flag = false; }
                }
                // returns true if 5 in a row with no overline
                if (flag) {
                    for (int k = 0; k < 5; ++k) {
                        changeBackground(i+k, j+k, "yellow");
                    }
                    return true;
                }
                flag = true;
            }
        }
    }
    // returns false if no connect 5
    return false;
}

// checks for connect 5 diagonally bottom left to top right
bool Board::checkFiveDiag2() {
    int player;
    bool flag = true;
    for (int i = 14; i >= 4; --i) {
        for (int j = 0; j < 11; ++j) {
            // checks if grid spot is not empty
            if (grid[i][j] != 0) {
                player = grid[i][j];
                // checks if next 4 spots matches the first
                for (int k = 1; k < 5; ++k) {
                    if (grid[i-k][j+k] != player) {
                        flag = false;
                        break;
                    }
                }
                // check for overline
                if (i + 1 <= 14 && j - 1 >= 0 && flag) {
                    if (grid[i+1][j-1] == player) { flag = false; }
                }
                if (i - 5 >= 0 && j + 5 <= 14 && flag) {
                    if (grid[i-5][j+5] == player) { flag = false; }
                }
                // returns true if 5 in a row with no overline
                if (flag) {
                    for (int k = 0; k < 5; ++k) {
                        changeBackground(i-k, j+k, "yellow");
                    }
                    return true;
                }
                flag = true;
            }
        }
    }
    // returns false if no connect 5
    return false;
}

// checks for double three rule; returns true if violates double threes
bool Board::checkDoubleThrees(int id) {
    int x = id/15;
    int y = id%15;
    int state;
    // set the state and update the grid for testing
    if (playerTurn == true) {
        state = 1;
        updateGrid(id, 1);
    } else {
        state = 2;
        updateGrid(id, 2);
    }
    // check if there are at least 2 open three patterns
    int checks = 0;
    if (checkDoubleThreesHori(x, y, state))  { checks++; }
    if (checkDoubleThreesVert(x, y, state))  { checks++; }
    if (checkDoubleThreesDiag1(x, y, state)) { checks++; }
    if (checkDoubleThreesDiag2(x, y, state)) { checks++; }
    updateGrid(id, 0);
    if (checks >= 2) { return true; }
    return false;
}

// checks for open three patterns horizontally, returns true if found
bool Board::checkDoubleThreesHori(int x, int y , int state) {
    // returns false if y is on the edge
    if (y == 0 || y == 14) { return false; }
    // iterates through all three patterns
    for (int it = 0; it < open3.length(); ++it) {
        // set i to first position in pattern
        int i = y - (open3[it].length() - 2);
        if (i < 0) { i = 0; }
        // iterates through the possible combination that has x,y
        while (i <= y && i + open3[it].length() - 1 <= 14) {
            // set flag to find pattern; if false, no pattern found
            bool flag = true;
            // compares grid with pattern and set flag if there is a difference
            for (int j = 0; j < open3[it].length(); ++j) {
                if (flag) {
                    if (open3[it][j] == 1) {
                        if (grid[x][i + j] != state) { flag = false; }
                    } else {
                        if (grid[x][i + j] != 0)     { flag = false; }
                    }
                }
            }
            // returns true if pattern found, else goes to next iteration
            if (flag) { return true; }
            ++i;
        }
    }
    return false;
}

// checks for open three patterns vertically, returns true if found
bool Board::checkDoubleThreesVert(int x, int y, int state) {
    // returns false if x is on the edge
    if (x == 0 || x == 14) { return false; }
    // iterates through all three patterns
    for (int it = 0; it < open3.length(); ++it) {
        // set i to first position in pattern
        int i = x - (open3[it].length() - 2);
        if (i < 0) { i = 0; }
        // iterates through the possible combination that has x,y
        while (i <= x && i + open3[it].length() - 1 <= 14) {
            // set flag to find pattern; if false, no pattern found
            bool flag = true;
            // compares grid with pattern and set flag if there is a difference
            for (int j = 0; j < open3[it].length(); ++j) {
                if (flag) {
                    if (open3[it][j] == 1) {
                        if (grid[i+j][y] != state) { flag = false; }
                    } else {
                        if (grid[i+j][y] != 0)     { flag = false; }
                    }
                }
            }
            // returns true if pattern found, else goes to next iteration
            if (flag) { return true; }
            ++i;
        }
    }
    return false;
}

// checks for open three patterns diagonally top left to bottom right, returns true if found
bool Board::checkDoubleThreesDiag1(int x, int y, int state) {
    // returns false if x or y is on the edge
    if (x == 0 || x == 14 || y == 0 || y == 14) { return false; }
    // iterates through all three patterns
    for (int it = 0; it < open3.length(); ++it) {
        // set i,j to first position in pattern
        int i = x - (open3[it].length() - 2);
        int j = y - (open3[it].length() - 2);
        while (i < 0 || j < 0) {
            ++i;
            ++j;
        }
        // iterates through the possible combination that has x,y
        while (i <= x && j <= y && i + open3[it].length() - 1 <= 14 && j + open3[it].length() - 1 <= 14) {
            // set flag to find pattern; if false, no pattern found
            bool flag = true;
            // compares grid with pattern and set flag if there is a difference
            for (int k = 0; k < open3[it].length(); ++k) {
                if (flag) {
                    if (open3[it][k] == 1) {
                        if (grid[i+k][j+k] != state) { flag = false; }
                    } else {
                        if (grid[i+k][j+k] != 0)     { flag = false; }
                    }
                }
            }
            // returns true if pattern found, else goes to next iteration
            if (flag) { return true; }
            ++i;
            ++j;
        }
    }
    return false;
}

// checks for open three patterns diagonally bottom left to top right, returns true if found
bool Board::checkDoubleThreesDiag2(int x, int y, int state) {
    // returns false if x or y is on the edge
    if (x == 0 || x == 14 || y == 0 || y == 14) { return false; }
    // iterates through all three patterns
    for (int it = 0; it < open3.length(); ++it) {
        // set i,j to first position in pattern
        int i = x + (open3[it].length() - 2);
        int j = y - (open3[it].length() - 2);
        while (i > 14 || j < 0) {
            --i;
            ++j;
        }
        // iterates through the possible combination that has x,y
        while (i >= x && j <= y && i - (open3[it].length() - 1) >= 0 && j + open3[it].length() - 1 <= 14) {
            // set flag to find pattern; if false, no pattern found
            bool flag = true;
            // compares grid with pattern and set flag if there is a difference
            for (int k = 0; k < open3[it].length(); ++k) {
                if (flag) {
                    if (open3[it][k] == 1) {
                        if (grid[i-k][j+k] != state) { flag = false; }
                    } else {
                        if (grid[i-k][j+k] != 0)     { flag = false; }
                    }
                }
            }
            // returns true if pattern found, else goes to next iteration
            if (flag) { return true; }
            --i;
            ++j;
        }
    }
    return false;
}

// changes background color for five in a row
void Board::changeBackground(int x, int y, QString color) {
    buttons[x*15+y]->setStyleSheet("background-color:" + color);
}

// computer AI chooses a button
int Board::computerAI() { 
    resetWeightGrid();
    weighHori();
    weighVert();
    weighDiag1();
    weighDiag2();
    // returns -1 if no move found
    return pickMaxWeight();
}

// checks the patterns horizontally and add the weights to weightGrid
void Board::weighHori() {
    bool flag;
    int x, y;
    // iterate through all patterns
    for (int it = 0; it < patterns.length(); ++it) {
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                flag = true;
                // checks if pattern matches
                for (int k = 0; k < patterns[it].length() - 1; ++k) {
                    if (flag) {
                        if (j + k < 15) { // check if within bounds
                            if (patterns[it][k] == 3) { // 3 is where the potential mark is
                                if (grid[i][j+k] == 0) { // updates x,y
                                    x = i;
                                    y = j + k;
                                } else { flag = false; }
                            } else { // checks pattern with grid
                                if (patterns[it][k] != grid[i][j+k]) { flag = false; }
                            }
                        } else { flag = false; }
                    }
                }
                // if flag is true, add the weight to the grid
                if (flag) { weightGrid[x][y] += patterns[it].back(); }
            }
        }
    }
}

// checks the patterns horizontally and add the weights to weightGrid
void Board::weighVert() {
    int x, y;
    bool flag;
    // iterate through all patterns
    for (int it = 0; it < patterns.length(); ++it) {
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                flag = true;
                // checks if pattern matches
                for (int k = 0; k < patterns[it].length() - 1; ++k) {
                    if (flag) {
                        if (i + k < 15) { // check if within bounds
                            if (patterns[it][k] == 3) { // 3 is where the potential mark is
                                if (grid[i+k][j] == 0) { // updates x,y
                                    x = i + k;
                                    y = j;
                                } else { flag = false; }
                            } else { // checks pattern with grid
                                if (patterns[it][k] != grid[i+k][j]) { flag = false; }
                            }
                        } else { flag = false; }
                    }
                }
                // if flag is true, add weight to the grid
                if (flag) { weightGrid[x][y] += patterns[it].back(); }
            }
        }
    }
}

// checks the patterns horizontally and add the weights to weightGrid
void Board::weighDiag1() {
    int x, y;
    bool flag;
    // iterate through all patterns
    for (int it = 0; it < patterns.length(); ++it) {
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                flag = true;
                // checks if pattern matches
                for (int k = 0; k < patterns[it].length() - 1; ++k) {
                    if (flag) {
                        if (i+k < 15 && j+k < 15) { // check if within bounds
                            if (patterns[it][k] == 3) { // 3 is where the potential mark is
                                if (grid[i+k][j+k] == 0) { // updates x,y
                                    x = i + k;
                                    y = j + k;
                                } else { flag = false; }
                            } else { // checks pattern with grid
                                if (patterns[it][k] != grid[i+k][j+k]) { flag = false; }
                            }
                        } else { flag = false; }
                    }
                }
                // if flag is true, add the weight to the grid
                if (flag) { weightGrid[x][y] += patterns[it].back(); }
            }
        }
    }
}

// checks the patterns horizontally and add the weights to weightGrid
void Board::weighDiag2() {
    int x, y;
    bool flag;
    // iterate through all patterns
    for (int it = 0; it < patterns.length(); ++it) {
        for (int i = 14; i >= 0; --i) {
            for (int j = 0; j < 15; ++j) {
                flag = true;
                // checks if pattern matches
                for (int k = 0; k < patterns[it].length() - 1; ++k) {
                    if (flag) {
                        if (i-k >= 0 && j+k < 15) { // check if within bounds
                            if (patterns[it][k] == 3) { // 3 is where the potential mark is
                                if (grid[i-k][j+k] == 0) { // updates x,y
                                    x = i - k;
                                    y = j + k;
                                } else { flag = false; }
                            } else { // checks pattern with grid
                                if (patterns[it][k] != grid[i-k][j+k]) { flag = false; }
                            }
                        } else { flag = false; }
                    }
                }
                // if flag is true, add the weight to the grid
                if (flag) { weightGrid[x][y] += patterns[it].back(); }
            }
        }
    }
}

// picks the button with the max weight from weightGrid
int Board::pickMaxWeight() {
    int pos, max = 0;
    // get max weight and check if it is valid
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (weightGrid[i][j] > max && checkValidMove(i*15+j)) {
                pos = i*15+j;
                max = weightGrid[i][j];
            }
        }
    }
    // returns -1, if there was no weight
    if (max == 0) { return -1; }
    // returns position
    return pos;
}
