#include "qtictactoesquare.h"

#include <QPainter>

QTicTacToeSquare::QTicTacToeSquare(TicTacToeBoard* board, int squareNo, QWidget *parent)
    : QWidget{parent},
      board_(board),
      squareNo_(squareNo) {
    assert(squareNo >= 0 && squareNo < 9);  // Square number must be on the board.
}

void QTicTacToeSquare::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QPen pen(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(0, 0, this->width(), this->height());
    painter.drawLine(0, this->height(), this->width(), 0);
}
