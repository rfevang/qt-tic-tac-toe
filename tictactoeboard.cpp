#include "tictactoeboard.h"

TicTacToeBoard::TicTacToeBoard() :
    board_(3, std::vector<Square>(3, EMPTY)) {}


TicTacToeBoard::Square TicTacToeBoard::getSquare(int x, int y) const {
    return board_[x][y];
}
