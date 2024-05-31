#include "game.h"
#include <iostream>

Game::Game() {
    initializeBoard();
    currentPlayer = 'X';
}

void Game::initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void Game::drawBoard() {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  -+-+-\n";
    }
}

bool Game::checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool Game::checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool Game::makeMove(int row, int col) {
    if (isValidMove(row, col)) {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool Game::isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void Game::play() {
    int row, col;
    bool gameWon = false, gameDrawn = false;

    while (!gameWon && !gameDrawn) {
        drawBoard();
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (makeMove(row, col)) {
            gameWon = checkWin();
            gameDrawn = checkDraw();
            if (!gameWon && !gameDrawn) {
                switchPlayer();
            }
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }

    drawBoard();
    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins!\n";
    } else if (gameDrawn) {
        std::cout << "The game is a draw.\n";
    }
}

