#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <vector>

class TicTacToeBoard
{
public:
    enum Square {
        X,
        O,
        EMPTY
    };
    TicTacToeBoard();

    Square getSquare(int x, int y) const;

private:
    std::vector<std::vector<Square>> board;
};

#endif // TICTACTOEBOARD_H
