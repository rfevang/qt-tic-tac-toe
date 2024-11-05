#include "computertictactoecontroller.h"

ComputerTicTacToeController::ComputerTicTacToeController(
            TicTacToeBoard* board, TicTacToeBoard::Player player) :
        QObject{board},
        player_(player),
        board_(board),
        enabled_(false) {
    // Use QueuedConnection here to prevent making moves while the board state
    // is being updated.
    connect(
        board,
        &TicTacToeBoard::nextToPlayChanged,
        this,
        &ComputerTicTacToeController::maybeMove,
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

void ComputerTicTacToeController::maybeMove() {
    // Only make a move if we're enabled and it is our player's turn.
    if (!enabled_ || player_ != board_->nextToPlay()) return;
    board_->makeComputerMove();
}
