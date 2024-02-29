#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "GridEnum.h"

#include <map>
#include <string>

const int ROWS = 6;
const int COLS = 7;

class GameBoard
{
public:
    GameBoard() = default;

    void DisplayGameBoard();

    bool PlayMove(int columnNum, gridMove type = Player);

    gameStatus GetGameState() const { return gameState; }

    gridMove* getBoard() { return board; }

    int GetCols() const { return COLS; }

    int GetRows() const { return ROWS; }

private:

    void CheckWin();

    bool Equals4(gridMove A, gridMove B, gridMove C, gridMove D);

    void DisplayWinningInfo(std::string winType);

    void DisplayDrawInfo();

    void PrintLine();

    void PrintNumbers(int row);

    void PrintColumnNumbers();
    
    gridMove board[ROWS * COLS] = {};

    gameStatus gameState = Playing;

    int numMoves = 1;

    std::map<int,char> translator = {{0, ' '}, {1, 'X'}, {2, 'O'}};

    std::map<int,std::string> winningTranslator = {{0, ""}, {1, "Player"}, {2, "Computer"}};
};
#endif
