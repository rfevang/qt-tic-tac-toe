#include "tictactoeboard.h"

TicTacToeBoard::TicTacToeBoard() :
    xSquares(0),
    oSquares(0),
    nextToPlay_(X) {}

bool isOwned(int squares, int squareNo) {
    return ((1 << squareNo) & squares) != 0;
}

TicTacToeBoard::Player TicTacToeBoard::getSquare(int squareNo) const {
    if (isOwned(xSquares, squareNo)) return X;
    if (isOwned(oSquares, squareNo)) return O;
    return NONE;
}

void TicTacToeBoard::markSquare(int squareNo) {
    // Ignore attempts to mark already owned squares.
    if (nextToPlay_ == NONE || isOwned(xSquares | oSquares, squareNo)) return;
    setSquare_(squareNo, nextToPlay_);
    if (!gameOver_) setNextToPlay_(nextToPlay_ == X ? O : X);
}

void TicTacToeBoard::restartGame() {
    xSquares = 0;
    oSquares = 0;
    setNextToPlay_(X);
    gameOver_ = false;
    emit gameRestarted();
}

void TicTacToeBoard::setSquare_(int squareNo, Player value) {
    int& squares = (value == X ? xSquares : oSquares);
    squares |= (1 << squareNo);
    emit squareChanged(squareNo, value);
    checkIfGameIsOver_();
}

void TicTacToeBoard::setNextToPlay_(Player player) {
    if (nextToPlay_ == player) return;
    nextToPlay_ = player;
    emit nextToPlayChanged(player);
}

// Checks whether a player with the given owned squares has won the game.
bool hasWon(int squares) {
    // Use octal bit representations, as it corresponds really well with a 3x3 board.
    static const int winningLines[] = {
        0007,  // Row 1
        0070,  // Row 2
        0700,  // Row 3
        0111,  // Column 1
        0222,  // Column 2
        0444,  // Column 3
        0124,  // Reverse diagonal
        0421,  // Normal diagonal
    };

    for (int i = 0; i < 8; i++) {
        if ((squares & winningLines[i]) == winningLines[i]) return true;
    }
    return false;
}

void TicTacToeBoard::checkIfGameIsOver_() {
    if (hasWon(xSquares)) declareGameOver_(X);
    else if (hasWon(oSquares)) declareGameOver_(O);
    else if ((xSquares | oSquares) == 0777) declareGameOver_(NONE);
}

void TicTacToeBoard::declareGameOver_(Player winner) {
    gameOver_ = true;
    emit gameOver(winner);
    setNextToPlay_(NONE);
}
