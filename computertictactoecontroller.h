#ifndef COMPUTERTICTACTOECONTROLLER_H
#define COMPUTERTICTACTOECONTROLLER_H

#include "tictactoeboard.h"

#include <QObject>

// Controller class controlling whether a computer player is active for a single
// side on a single board.
class ComputerTicTacToeController : public QObject
{
    Q_OBJECT
public:
    explicit ComputerTicTacToeController(TicTacToeBoard* board, TicTacToeBoard::Player player);

signals:
    // Signals that the value of the enabled flag has changed.
    void enabledChanged(bool enabled);

public slots:
    // Sets enabled status to the given value.
    void setEnabled(bool enabled);

private:
    // The player this controller is in charge of.
    TicTacToeBoard::Player player_;
    // The board the controller uses.
    TicTacToeBoard* board_;
    // Whether the player should play a computer move when it is it's turn.
    bool enabled_;

private slots:
    // Makes a move on the board if the computer player is enabled and it is it's turn.
    void maybeMove();
};

#endif // COMPUTERTICTACTOECONTROLLER_H
