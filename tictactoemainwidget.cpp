#include "computertictactoecontroller.h"
#include "playersettingsview.h"
#include "tictactoemainwidget.h"
#include "tictactoeboard.h"
#include "tictactoegrid.h"
#include <QGridLayout>

#include <QCheckBox>
#include <QPushButton>

MainWidget::MainWidget(TicTacToeBoard* board, QWidget* parent)
    : QWidget{parent} {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    mainLayout->addWidget(new TicTacToeGrid(board, this));

    QVBoxLayout* controlsLayout = new QVBoxLayout();
    mainLayout->addLayout(controlsLayout);
    controlsLayout->addWidget(new PlayerSettingsView(board, TicTacToeBoard::X, this));
    controlsLayout->addWidget(new PlayerSettingsView(board, TicTacToeBoard::O, this));

    QPushButton* restartButton = new QPushButton(tr("&Restart"), this);
    controlsLayout->addWidget(restartButton);
    connect(restartButton, &QPushButton::clicked, board, &TicTacToeBoard::restartGame);

    controlsLayout->addStretch();
}
