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

    // Debugging border
    painter.drawRect(contentsRect());

    int side = std::min(width(), height());
    // Pretend we're always 100x100 when deciding draw coordinates.
    painter.scale(side / 100.0, side / 100.0);
    int margin = 15;
    painter.translate(margin / 2.0, margin / 2.0);
    if (square == TicTacToeBoard::X) {
        QPen pen(Qt::red);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawLine(0, 0, 100 - margin, 100 - margin);
        painter.drawLine(0, 100 - margin, 100 - margin, 0);
    }
    if (square == TicTacToeBoard::O) {
        QPen pen(Qt::green);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawEllipse(QRect(0, 0, 100 - margin, 100 - margin));
    }
}
