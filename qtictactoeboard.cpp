#include "qtictactoeboard.h"
#include "qtictactoesquare.h"
#include "tictactoeboard.h"
#include <QGridLayout>

#include <QPushButton>

QTicTacToeBoard::QTicTacToeBoard(TicTacToeBoard* board, QWidget* parent)
    : QWidget{parent},
      board_(board) {
    QGridLayout* layout = new QGridLayout(this);
    for(int i = 0; i < 9; i++) {
        layout->addWidget(new QTicTacToeSquare(board, i), i/3, i%3);
    }
}
