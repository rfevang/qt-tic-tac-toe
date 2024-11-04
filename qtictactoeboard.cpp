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

    QCheckBox* computerPlayer1 = new QCheckBox("Computer controls player 1", this);
    layout->addWidget(computerPlayer1, 3, 0, 1, 2);
    QCheckBox* computerPlayer2 = new QCheckBox("Computer controls player 2", this);
    layout->addWidget(computerPlayer2, 4, 0, 1, 2);
    QPushButton* restartButton = new QPushButton(tr("&Restart"), this);
    layout->addWidget(restartButton, 4, 2, 1, 1);



    connect(restartButton, &QPushButton::clicked, board_, &TicTacToeBoard::restartGame);
}

QSize QTicTacToeBoard::sizeHint() const {
    return QSize(400,480);
}
