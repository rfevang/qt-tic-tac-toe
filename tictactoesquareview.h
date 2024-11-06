#ifndef TICTACTOESQUAREVIEW_H
#define TICTACTOESQUAREVIEW_H

#include "tictactoeboard.h"

#include <QWidget>


// Visual representation of a single square on a Tic-Tac-Toe board.
class TicTacToeSquareView : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToeSquareView(
        TicTacToeBoard* board,
        int squareNo,
        QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    // Which square on the board this widget represents.
    int squareNo_;
    // The Tic-Tac-Toe board owning the square.
    TicTacToeBoard* board_;
};

#endif // TICTACTOESQUAREVIEW_H
