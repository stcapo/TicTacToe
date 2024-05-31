#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game();
    void play();

private:
    char board[3][3];
    char currentPlayer;

    void initializeBoard();
    void drawBoard();
    bool checkWin();
    bool checkDraw();
    void switchPlayer();
    bool makeMove(int row, int col);
    bool isValidMove(int row, int col);
};

#endif // GAME_H

