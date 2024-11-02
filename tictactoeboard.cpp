#include "tictactoeboard.h"

TicTacToeBoard::TicTacToeBoard() :
    board_(9, EMPTY),
    nextToPlay_(X) {}


TicTacToeBoard::Square TicTacToeBoard::getSquare(int squareNo) const {
    if (squareNo < 0 || squareNo >= 9) return EMPTY;
    return board_[squareNo];
}

void TicTacToeBoard::markSquare(int squareNo) {
    if (squareNo < 0 || squareNo >= 9 || board_[squareNo] != EMPTY) return;
    board_[squareNo] = nextToPlay_;
    nextToPlay_ = nextToPlay_ == X ? O : X;
}
