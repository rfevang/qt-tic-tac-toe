#include "playersettingsview.h"

#include "computertictactoecontroller.h"
#include "tictactoeboard.h"

#include <QCheckBox>
#include <QScrollBar>
#include <QVBoxLayout>

QString titleForPlayer(TicTacToeBoard::Player player) {
    switch (player) {
        case TicTacToeBoard::X:
            return "Player 1 options";
        case TicTacToeBoard::O:
            return "Player 2 options";
        default:
            // Shouldn't happen.
            assert(false);
    }
}

PlayerSettingsView::PlayerSettingsView(TicTacToeBoard* board, TicTacToeBoard::Player player, QWidget *parent)
    : QGroupBox{titleForPlayer(player), parent} {
    setFlat(false);
    ComputerTicTacToeController* controller = new ComputerTicTacToeController(board, player);
    QVBoxLayout* layout = new QVBoxLayout(this);

    QCheckBox* computerEnabled = new QCheckBox("Computer moves", this);
    layout->addWidget(computerEnabled);

    connect(
        controller,
        &ComputerTicTacToeController::enabledChanged,
        computerEnabled,
        &QCheckBox::setChecked);
    connect(
        computerEnabled,
        &QCheckBox::checkStateChanged,
        controller,
        &ComputerTicTacToeController::setEnabled);


    QScrollBar* difficultySlider = new QScrollBar(Qt::Horizontal, this);
    difficultySlider->setRange(0, 100);
    difficultySlider->setValue(controller->strength());
    layout->addWidget(difficultySlider);
    connect(
        controller,
        &ComputerTicTacToeController::strengthChanged,
        difficultySlider,
        &QScrollBar::setValue);
    connect(
        difficultySlider,
        &QScrollBar::valueChanged,
        controller,
        &ComputerTicTacToeController::setStrength);
}
