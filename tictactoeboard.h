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

    Square getSquare(int squareNo) const;

private:
    std::vector<Square> board_;
};

#endif // TICTACTOEBOARD_H
