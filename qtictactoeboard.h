#ifndef QTICTACTOEBOARD_H
#define QTICTACTOEBOARD_H

#include "tictactoeboard.h"
#include <QWidget>

class QTicTacToeBoard : public QWidget
{
    Q_OBJECT
public:
    explicit QTicTacToeBoard(TicTacToeBoard *board, QWidget *parent = nullptr);
    //~QTicTacToeBoard();

signals:

private:
    TicTacToeBoard *board;
};

#endif // QTICTACTOEBOARD_H
