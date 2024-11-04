#include "computertictactoecontroller.h"
#include "qtictactoeboard.h"
#include "qtictactoesquare.h"
#include "tictactoeboard.h"
#include <QGridLayout>

#include <QCheckBox>
#include <QPushButton>

QTicTacToeBoard::QTicTacToeBoard(TicTacToeBoard* board, QWidget* parent)
    : QWidget{parent},
      board_(board) {
    QGridLayout* layout = new QGridLayout(this);
    for(int i = 0; i < 9; i++) {
        layout->addWidget(new QTicTacToeSquare(board, i), i/3, i%3);
    }

    ComputerTicTacToeController* player1Controller = new ComputerTicTacToeController(board, TicTacToeBoard::X);
    QCheckBox* player1CheckBox = new QCheckBox("Computer controls player 1", this);
    layout->addWidget(player1CheckBox, 3, 0, 1, 2);
    connectComputerCheckbox_(player1Controller, player1CheckBox);

    ComputerTicTacToeController* player2Controller = new ComputerTicTacToeController(board, TicTacToeBoard::O);
    QCheckBox* player2CheckBox = new QCheckBox("Computer controls player 2", this);
    layout->addWidget(player2CheckBox, 4, 0, 1, 2);
    connectComputerCheckbox_(player2Controller , player2CheckBox);

    QPushButton* restartButton = new QPushButton(tr("&Restart"), this);
    layout->addWidget(restartButton, 4, 2, 1, 1);

    connect(restartButton, &QPushButton::clicked, board_, &TicTacToeBoard::restartGame);
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

QSize QTicTacToeBoard::sizeHint() const {
    return QSize(400,480);
}
