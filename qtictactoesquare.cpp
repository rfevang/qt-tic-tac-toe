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
    painter.setRenderHint(QPainter::Antialiasing);
    TicTacToeBoard::Square square = board_->getSquare(squareNo_);

    if (square == TicTacToeBoard::X) {
        QPen pen(Qt::red);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawLine(0, 0, this->width(), this->height());
        painter.drawLine(0, this->height(), this->width(), 0);
    }
    if (square == TicTacToeBoard::O) {
        QPen pen(Qt::green);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawEllipse(0, 0, this->width(), this->height());
    }
}
