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
    setNextToPlay_(nextToPlay_ == X ? O : X);
}

void TicTacToeBoard::restartGame() {
    for (int i = 0; i < 9; i++) {
        setSquare_(i, NONE);
    }
    setNextToPlay_(X);
    emit gameRestarted(NONE);
}

void TicTacToeBoard::setSquare_(int squareNo, Player value) {
    if (board_[squareNo] == value) return;
    board_[squareNo] = value;
    emit squareChanged(squareNo, value);
}

void TicTacToeBoard::setNextToPlay_(Player player) {
    if (nextToPlay_ == player) return;
    nextToPlay_ = player;
    emit nextToPlayChanged(player);
}
