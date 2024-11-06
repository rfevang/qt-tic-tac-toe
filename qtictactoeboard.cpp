#include "computertictactoecontroller.h"
#include "playersettingsview.h"
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
    controlsLayout->addWidget(new PlayerSettingsView(board, TicTacToeBoard::X, this));
    controlsLayout->addWidget(new PlayerSettingsView(board, TicTacToeBoard::O, this));

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

