#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <QObject>

// Represents a single board to play Tic-Tac-Toe on.
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
    explicit TicTacToeBoard(QObject* parent = nullptr);

    // Retrieves the ownership status of the given square.
    Player getSquare(int squareNo) const;

    // Marks the square for the player who's turn it is. If the square is not
    // empty, or there is no next player this does nothing.
    void markSquare(int squareNo);

    // Returns which player is currently next to play.
    Player nextToPlay() const;

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
    // Make a computer move for the player who's turn it is.
    // Strength should be a number between 0 and 100, where 0 is a computer
    // making random moves, and 100 is a computer playing perfectly.
    void makeComputerMove(int strength = 0);

private:
    // Bitmask of player squares.
    int xSquares, oSquares;
    // Which player is next to play.
    Player nextToPlay_;
    // true if the game is over.
    bool gameOver_;

    // Marks the given square as being owned by the given player.
    void setSquare_(int squareNo, Player value);
    // Updates nextToPlay_ to the specified player.
    void setNextToPlay_(Player player);
    // Checks if the game is over.
    void checkIfGameIsOver_();
    // Declares the game is over, emitting any necessary signals to notify
    // interested parties.
    void declareGameOver_(Player winner);
    // Selects a random available move. If there are no moves, -1 is returned.
    int selectRandomMove_();
    // Selects an optimal move. If there are no moves, -1 is returned.
    int selectBestMove_(int playerSquares, int opponentSquares);
};

#endif // TICTACTOEBOARD_H
