#include "computertictactoecontroller.h"
#include "qtictactoeboard.h"
#include "tictactoeboard.h"
#include "tictactoegrid.h"
#include <QGridLayout>

#include <QCheckBox>
#include <QPushButton>

QTicTacToeBoard::QTicTacToeBoard(TicTacToeBoard* board, QWidget* parent)
    : QWidget{parent} {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    mainLayout->addWidget(new TicTacToeGrid(board, this));

    QVBoxLayout* controlsLayout = new QVBoxLayout();
    mainLayout->addLayout(controlsLayout);

    ComputerTicTacToeController* player1Controller = new ComputerTicTacToeController(board, TicTacToeBoard::X);
    QCheckBox* player1CheckBox = new QCheckBox("Computer controls player 1", this);
    controlsLayout->addWidget(player1CheckBox);
    connectComputerCheckbox_(player1Controller, player1CheckBox);

    ComputerTicTacToeController* player2Controller = new ComputerTicTacToeController(board, TicTacToeBoard::O);
    QCheckBox* player2CheckBox = new QCheckBox("Computer controls player 2", this);
    controlsLayout->addWidget(player2CheckBox);
    connectComputerCheckbox_(player2Controller , player2CheckBox);

    QPushButton* restartButton = new QPushButton(tr("&Restart"), this);
    controlsLayout->addWidget(restartButton);
    connect(restartButton, &QPushButton::clicked, board, &TicTacToeBoard::restartGame);

    controlsLayout->addStretch();
}

void QTicTacToeBoard::connectComputerCheckbox_(ComputerTicTacToeController* controller, QCheckBox* checkbox) {
    connect(
        controller,
        &ComputerTicTacToeController::enabledChanged,
        checkbox,
        &QCheckBox::setChecked);
    connect(
        checkbox,
        &QCheckBox::checkStateChanged,
        controller,
        &ComputerTicTacToeController::setEnabled);
}

