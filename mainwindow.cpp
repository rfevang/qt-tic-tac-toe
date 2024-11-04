#include "mainwindow.h"

#include "qtictactoeboard.h"

#include <QGridLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    board_ = std::make_unique<TicTacToeBoard>();
    this->setCentralWidget(new QTicTacToeBoard(board_.get()));
}

MainWindow::~MainWindow()
{
}
