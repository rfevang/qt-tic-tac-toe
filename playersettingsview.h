#ifndef PLAYERSETTINGSVIEW_H
#define PLAYERSETTINGSVIEW_H

#include "tictactoeboard.h"

#include <QGroupBox>

// Contains knobs and switches for settings related to a single Tic-Tac-Toe
// player.
class PlayerSettingsView : public QGroupBox
{
    Q_OBJECT
public:
    explicit PlayerSettingsView(
        TicTacToeBoard* board,
        TicTacToeBoard::Player player,
        QWidget* parent = nullptr);

signals:
};

#endif // PLAYERSETTINGSVIEW_H
