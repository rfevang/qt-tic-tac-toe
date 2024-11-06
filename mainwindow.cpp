#include "mainwindow.h"

#include "tictactoemainwidget.h"

#include <QGridLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    board_ = std::make_unique<TicTacToeBoard>();
    this->setCentralWidget(new MainWidget(board_.get()));
}

MainWindow::~MainWindow()
{
}
