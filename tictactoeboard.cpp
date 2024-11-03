#include "tictactoeboard.h"

TicTacToeBoard::TicTacToeBoard() :
    board_(9, NONE),
    nextToPlay_(X) {}


TicTacToeBoard::Player TicTacToeBoard::getSquare(int squareNo) const {
    if (squareNo < 0 || squareNo >= 9) return NONE;
    return board_[squareNo];
}

void TicTacToeBoard::markSquare(int squareNo) {
    if (squareNo < 0 || squareNo >= 9 || board_[squareNo] != NONE) return;
    setSquare_(squareNo, nextToPlay_);
    if (!gameOver_) setNextToPlay_(nextToPlay_ == X ? O : X);
}

void TicTacToeBoard::restartGame() {
    for (int i = 0; i < 9; i++) {
        setSquare_(i, NONE);
    }
    setNextToPlay_(X);
    gameOver_ = false;
    emit gameRestarted();
}

void TicTacToeBoard::setSquare_(int squareNo, Player value) {
    if (board_[squareNo] == value) return;
    board_[squareNo] = value;
    emit squareChanged(squareNo, value);
    checkIfGameIsOver_();
}

void TicTacToeBoard::setNextToPlay_(Player player) {
    if (nextToPlay_ == player) return;
    nextToPlay_ = player;
    emit nextToPlayChanged(player);
}

void TicTacToeBoard::checkIfGameIsOver_() {
    // Checks vertical lines, then horizontal, then the two diagonals.
    // First squares to check for each combination.
    static const int startSquares[] = {0, 1, 2, 0, 3, 6, 0, 2};
    // Increment from the previous square to the next square to check for each
    // combination.
    static const int increment[] = {3, 3, 3, 1, 1, 1, 4, 2};

    for(int i = 0; i < 8; i++) {
        Player maybeWinner = board_[startSquares[i]];
        if (maybeWinner == NONE) continue;
        bool won = true;
        for (int j = 1; j < 3; j++) {
            if (board_[startSquares[i] + j * increment[i]] != maybeWinner) won = false;
        }
        if (won) {
            declareGameOver_(maybeWinner);
            return;
        }
    }

    // Check for a filled board (draw).
    for (int i = 0; i < 9; i++) {
        // Still game to be played, even if it may be impossible to win.
        if (board_[i] == NONE) return;
    }
    // All squares owned by a player, declare draw.
    declareGameOver_(NONE);
}

void TicTacToeBoard::declareGameOver_(Player winner) {
    gameOver_ = true;
    emit gameOver(winner);
    setNextToPlay_(NONE);
}
