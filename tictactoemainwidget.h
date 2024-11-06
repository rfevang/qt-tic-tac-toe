#ifndef TICTACTOEMAINWIDGET_H
#define TICTACTOEMAINWIDGET_H

#include "tictactoeboard.h"
#include <QWidget>

class ComputerTicTacToeController;
class QCheckBox;

// Main application widget for Tic-Tac-Toe.
class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(TicTacToeBoard* board, QWidget* parent = nullptr);
};

#endif // TICTACTOEMAINWIDGET_H
