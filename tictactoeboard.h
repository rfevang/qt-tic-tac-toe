#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <QObject>
#include <vector>

class TicTacToeBoard : public QObject
{
    Q_OBJECT
public:
    enum Player {
        NONE,
        X,
        O,
    };
    TicTacToeBoard();

    // Retrieve the ownership status of the given square.
    Player getSquare(int squareNo) const;

    // Marks the square for the player who's turn it is. If the square is not
    // empty, or there is no next player this does nothing.
    void markSquare(int squareNo);

signals:
    // The ownership status of a square has changed.
    void squareChanged(int squareNo, Player squareOwner);
    // A new game has started. The previous game was won by the given player.
    void gameRestarted(Player winner);
    // Which player's move is next has changed.
    void nextToPlayChanged(Player nextToPlay);

public slots:
    // Clears the board, setting up for a new game.
    void restartGame();

private:
    void setSquare_(int squareNo, Player value);
    void setNextToPlay_(Player player);

    // Current board state.
    std::vector<Player> board_;
    // Which player is next to play.
    Player nextToPlay_;
};

#endif // TICTACTOEBOARD_H
