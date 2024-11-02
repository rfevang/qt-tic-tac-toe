#ifndef QTICTACTOESQUARE_H
#define QTICTACTOESQUARE_H

#include "tictactoeboard.h"

#include <QWidget>


// Graphical representation of a single square on a Tic-Tac-Toe board.
class QTicTacToeSquare : public QWidget
{
    Q_OBJECT
public:
    explicit QTicTacToeSquare(TicTacToeBoard* board, int squareNo, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;


signals:

private:
    // Represents which square on the board this widget represents.
    int squareNo_;
    // The Tic-Tac-Toe board owning the square.
    TicTacToeBoard* board_;
};

#endif // QTICTACTOESQUARE_H
