#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <QObject>
#include <vector>

class TicTacToeBoard : public QObject
{
    Q_OBJECT
public:
    // Represent one of the players of Tic-Tac-Toe. NONE is used for cases where
    // there is not a player answer. For instance, NONE is given for ownership
    // status of square's without an X or O, or as winner status of a tied game.
    enum Player {
        NONE,
        X,
        O,
    };
    TicTacToeBoard();

    // Retrieves the ownership status of the given square.
    Player getSquare(int squareNo) const;

    // Marks the square for the player who's turn it is. If the square is not
    // empty, or there is no next player this does nothing.
    void markSquare(int squareNo);

signals:
    // The ownership status of a square has changed.
    void squareChanged(int squareNo, Player squareOwner);
    // A new game has started.
    void gameRestarted();
    // Which player's move is next has changed.
    void nextToPlayChanged(Player nextToPlay);
    // The game is over. It was won by the given player.
    void gameOver(Player player);

public slots:
    // Clears the board, setting up for a new game.
    void restartGame();

private:
    // Marks the given square as being owned by the given player.
    void setSquare_(int squareNo, Player value);
    // Updates nextToPlay_ to the specified player.
    void setNextToPlay_(Player player);
    // Checks if the game is over.
    void checkIfGameIsOver_();
    // Declares the game is over, emitting any necessary signals to notify
    // interested parties.
    void declareGameOver_(Player winner);

    // Current board state.
    std::vector<Player> board_;
    // Which player is next to play.
    Player nextToPlay_;
    // true if the game is over.
    bool gameOver_;
};

#endif // TICTACTOEBOARD_H
