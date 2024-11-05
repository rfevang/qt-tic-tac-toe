#ifndef QTICTACTOEBOARD_H
#define QTICTACTOEBOARD_H

#include "tictactoeboard.h"
#include <QWidget>

class ComputerTicTacToeController;
class QCheckBox;

class QTicTacToeBoard : public QWidget
{
    Q_OBJECT
public:
    explicit QTicTacToeBoard(TicTacToeBoard* board, QWidget* parent = nullptr);

private:
    // Hooks up signals and slots between a checkbox and controller.
    void connectComputerCheckbox_(ComputerTicTacToeController* controller, QCheckBox* checkbox);
};

#endif // QTICTACTOEBOARD_H
