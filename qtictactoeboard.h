#ifndef QTICTACTOEBOARD_H
#define QTICTACTOEBOARD_H

#include "tictactoeboard.h"
#include <QWidget>

class QTicTacToeBoard : public QWidget
{
    Q_OBJECT
public:
    explicit QTicTacToeBoard(TicTacToeBoard* board, QWidget* parent = nullptr);

    QSize sizeHint() const override;

private:
    TicTacToeBoard* board_;
};

#endif // QTICTACTOEBOARD_H
