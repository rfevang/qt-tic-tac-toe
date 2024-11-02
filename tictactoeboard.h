#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <vector>

class TicTacToeBoard
{
public:
    enum Square {
        EMPTY,
        X,
        O,
    };
    TicTacToeBoard();

    Square getSquare(int squareNo) const;

    // Marks the square for the player who's turn it is. If the square is not
    // empty this does nothing.
    void markSquare(int squareNo);

private:
    // Current board state.
    std::vector<Square> board_;
    // Which player is next to play.
    Square nextToPlay_;
};

#endif // TICTACTOEBOARD_H
