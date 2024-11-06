#ifndef TICTACTOEGRID_H
#define TICTACTOEGRID_H

#include <QWidget>

class TicTacToeBoard;

// Visual representation of a TicTacToeBoard.
class TicTacToeGrid : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToeGrid(TicTacToeBoard* board, QWidget *parent = nullptr);

    QSize sizeHint() const override;


};

#endif // TICTACTOEGRID_H
