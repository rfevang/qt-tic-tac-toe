#include "tictactoegrid.h"

#include "qtictactoesquare.h"

#include <QGridLayout>

TicTacToeGrid::TicTacToeGrid(TicTacToeBoard* board, QWidget *parent)
    : QWidget{parent} {
    QGridLayout* layout = new QGridLayout(this);
    for(int i = 0; i < 9; i++) {
        layout->addWidget(new QTicTacToeSquare(board, i), i/3, i%3);
    }
}

QSize TicTacToeGrid::sizeHint() const {
    return QSize(400,400);
}
