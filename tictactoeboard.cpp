#include "tictactoeboard.h"

TicTacToeBoard::TicTacToeBoard() :
    board_(9, EMPTY) {
    // Temp for visualization
    board_[4] = X;
    board_[3] = X;
    board_[2] = X;
    board_[0] = O;
    board_[8] = O;
}


TicTacToeBoard::Square TicTacToeBoard::getSquare(int squareNo) const {
    if (squareNo < 0 || squareNo >= 9) return EMPTY;
    return board_[squareNo];
}
