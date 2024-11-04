#include "computertictactoecontroller.h"

ComputerTicTacToeController::ComputerTicTacToeController(
            TicTacToeBoard* board, TicTacToeBoard::Player player) :
        QObject{board},
        player_(player),
        nextToPlay_(board->nextToPlay()),
        board_(board),
        enabled_(false) {
    connect(
        board,
        &TicTacToeBoard::nextToPlayChanged,
        this,
        &ComputerTicTacToeController::playersTurn,
        Qt::QueuedConnection);
    connect(
        board,
        &TicTacToeBoard::gameRestarted,
        this,
        &ComputerTicTacToeController::maybeMove,
        Qt::QueuedConnection);
}

void ComputerTicTacToeController::setEnabled(bool enabled) {
    if (enabled == enabled_) return;
    enabled_ = enabled;
    emit enabledChanged(enabled);
    maybeMove();
}

void ComputerTicTacToeController::playersTurn(TicTacToeBoard::Player player) {
    nextToPlay_ = player;
    maybeMove();
}

void ComputerTicTacToeController::maybeMove() {
    // Only make a move if we're enabled and it is our player's turn.
    if (!enabled_ || player_ != nextToPlay_) return;
    board_->makeComputerMove();
}
