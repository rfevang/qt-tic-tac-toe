#include "tictactoesquareview.h"

#include <QPainter>

TicTacToeSquareView::TicTacToeSquareView(TicTacToeBoard* board, int squareNo, QWidget *parent)
    : QWidget{parent},
      board_(board),
      squareNo_(squareNo) {
    assert(squareNo >= 0 && squareNo < 9);  // Square number must be on the board.
    connect(board, &TicTacToeBoard::squareChanged, this, [=](int changedSquareNo){
        if (changedSquareNo == squareNo_) update();
    });
    connect(board, &TicTacToeBoard::gameRestarted, this, qOverload<>(&QWidget::update));
}

void TicTacToeSquareView::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    TicTacToeBoard::Player square = board_->getSquare(squareNo_);

    // Debugging border
    painter.drawRect(contentsRect());

    int side = std::min(width(), height());
    // Pretend we're always 100x100 when deciding draw coordinates.
    painter.scale(side / 100.0, side / 100.0);

    int margin = 15;
    if (square == TicTacToeBoard::X) {
        QPen pen(Qt::red);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawLine(margin, margin, 100 - margin, 100 - margin);
        painter.drawLine(margin, 100 - margin, 100 - margin, margin);
    }
    if (square == TicTacToeBoard::O) {
        QPen pen(Qt::green);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawEllipse(QRect(margin, margin, 100 - 2 * margin, 100 - 2 * margin));
    }
}

void TicTacToeSquareView::mousePressEvent(QMouseEvent* event) {
    board_->markSquare(squareNo_);
}
