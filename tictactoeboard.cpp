#include "tictactoeboard.h"

// Checks whether a player with the given owned squares has won the game.
bool hasWon(int squares) {
    // Use octal bit representations, as it corresponds really well with a 3x3 board.
    static const int winningLines[] = {
        0007,  // Row 1
        0070,  // Row 2
        0700,  // Row 3
        0111,  // Column 1
        0222,  // Column 2
        0444,  // Column 3
        0124,  // Reverse diagonal
        0421,  // Normal diagonal
    };

    for (int i = 0; i < 8; i++) {
        if ((squares & winningLines[i]) == winningLines[i]) return true;
    }
    return false;
}

TicTacToeBoard::TicTacToeBoard(QObject* parent) :
    QObject{parent},
    xSquares(0),
    oSquares(0),
    nextToPlay_(X) {}

bool isOwned(int squares, int squareNo) {
    return ((1 << squareNo) & squares) != 0;
}

TicTacToeBoard::Player TicTacToeBoard::getSquare(int squareNo) const {
    if (isOwned(xSquares, squareNo)) return X;
    if (isOwned(oSquares, squareNo)) return O;
    return NONE;
}

void TicTacToeBoard::markSquare(int squareNo) {
    // Ignore attempts to mark already owned squares.
    if (nextToPlay_ == NONE || isOwned(xSquares | oSquares, squareNo)) return;
    setSquare_(squareNo, nextToPlay_);
    if (!gameOver_) setNextToPlay_(nextToPlay_ == X ? O : X);
}

TicTacToeBoard::Player TicTacToeBoard::nextToPlay() const {
    return nextToPlay_;
}

void TicTacToeBoard::restartGame() {
    xSquares = 0;
    oSquares = 0;
    setNextToPlay_(X);
    gameOver_ = false;
    emit gameRestarted();
}

void TicTacToeBoard::makeComputerMove(int strength) {
    int move = -1;
    if ((rand() % 101) > strength) {
        move = selectRandomMove_();
    } else {
        int playerSquares = (nextToPlay_ == X ? xSquares : oSquares);
        int opponentSquares = (nextToPlay_ == X ? oSquares : xSquares);
        move = selectBestMove_(playerSquares, opponentSquares);
    }
    if (move != -1) markSquare(move);
}

int TicTacToeBoard::selectRandomMove_() {
    int base = rand() % 9;
    for(int i = 0; i < 9; i++) {
        int squareNo = (base+i)%9;
        if (isOwned(xSquares | oSquares, squareNo)) continue;
        return squareNo;
    }
    return -1;
}

struct Move {
    Move(int squareNo, int score) : squareNo(squareNo), score(score) {}
    int squareNo;
    int score;
};

// Scores a position, and returns an optimal move leading to that score.
// Returned scores are 1 if the position is lost, 0 if it's a draw, and
// -1 if it's won.
Move scorePosition(int playerSquares, int opponentSquares) {
    // It's lost if the opponent won on the last move.
    if (hasWon(opponentSquares)) return Move(-1, 1);
    // Filled board with no winner yet means draw.
    if ((playerSquares | opponentSquares) == 0777) return Move(-1, 0);

    std::vector<int> bestMoves;
    int bestScore = -1;
    for (int i = 0; i < 9; i++) {
        if (isOwned(playerSquares | opponentSquares, i)) continue;
        Move moveScore = scorePosition(opponentSquares, playerSquares | (1 << i));
        if (moveScore.score > bestScore) {
            bestScore = moveScore.score;
            bestMoves.clear();
        }
        if (moveScore.score == bestScore) bestMoves.push_back(i);
    }
    return Move(bestMoves[rand() % bestMoves.size()], -bestScore);
}

int TicTacToeBoard::selectBestMove_(int playerSquares, int opponentSquares) {
    return scorePosition(playerSquares, opponentSquares).squareNo;
}

void TicTacToeBoard::setSquare_(int squareNo, Player value) {
    int& squares = (value == X ? xSquares : oSquares);
    squares |= (1 << squareNo);
    emit squareChanged(squareNo, value);
    checkIfGameIsOver_();
}

void TicTacToeBoard::setNextToPlay_(Player player) {
    if (nextToPlay_ == player) return;
    nextToPlay_ = player;
    emit nextToPlayChanged(player);
}

void TicTacToeBoard::checkIfGameIsOver_() {
    if (hasWon(xSquares)) declareGameOver_(X);
    else if (hasWon(oSquares)) declareGameOver_(O);
    else if ((xSquares | oSquares) == 0777) declareGameOver_(NONE);
}

void TicTacToeBoard::declareGameOver_(Player winner) {
    gameOver_ = true;
    emit gameOver(winner);
    setNextToPlay_(NONE);
}
