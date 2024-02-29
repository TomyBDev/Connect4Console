#include "GameBoard.h"

#include <iostream>

void GameBoard::DisplayGameBoard()
{
    std::cout << "-------+++ Connect4 +++-------" << "\n\n";
    
    PrintColumnNumbers();
    
    for (int i = 0; i < ROWS; ++i)
    {
        PrintNumbers(i);
        PrintLine();
    }
}

bool GameBoard::PlayMove(int columnNum, gridMove type)
{
    bool bValidMove = false;

    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (!board[COLS * i + columnNum])
        {
            board[COLS * i + columnNum] = type;
            CheckWin();
            bValidMove = true;
            if (numMoves++ >= (COLS * ROWS) && gameState == Playing)
            {
                gameState = Draw;
                DisplayDrawInfo();
            }
            return bValidMove;
        }
    }

    return bValidMove;
}

void GameBoard::CheckWin()
{
    // Horizontal Check
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j <= COLS - 4; ++j)
        {
            if (Equals4(board[i*COLS+(j + 0)], board[i*COLS+(j + 1)], board[i*COLS+(j + 2)], board[i*COLS+(j + 3)]))
            {
                gameState = static_cast<gameStatus>(board[i*COLS+(j + 0)]);
                DisplayWinningInfo("Horizontal");
            }
        }
    }

    // Vertical Check
    for (int i = 0; i < COLS; ++i)
    {
        for (int j = 0; j <= ROWS - 4; ++j)
        {
            if (Equals4(board[(j+0)*COLS+i], board[(j+1)*COLS+i], board[(j+2)*COLS+i], board[(j+3)*COLS+i]))
            {
                gameState = static_cast<gameStatus>(board[(j+0)*COLS+i]);
                DisplayWinningInfo("Vertical");
            }
        }
    }

    
    // Diagonal Check
    
    /*if (Equals3(board[0], board[4], board[8]))
    {
        gameState = static_cast<gameStatus>(board[4]);
        DisplayWinningInfo("Diagonal");
    }
    else if (Equals3(board[2], board[4], board[6]))
    {
        gameState = static_cast<gameStatus>(board[4]);
        DisplayWinningInfo("Diagonal");
    }*/
    
}

bool GameBoard::Equals4(gridMove A, gridMove B, gridMove C, gridMove D)
{
    return (A == B && B == C && C==D && A != Empty);
}

void GameBoard::DisplayWinningInfo(std::string winType)
{
    system("CLS");
    DisplayGameBoard();
    std::cout << "\n" << winningTranslator[gameState] << " won with a " << winType << " match.";
    
}

void GameBoard::DisplayDrawInfo()
{
    system("CLS");
    DisplayGameBoard();
    std::cout << "\n" <<  "Game was a draw.";
 
}

void GameBoard::PrintLine()
{
    for (int i = 1; i < COLS; ++i)
        std::cout << "+---";
    
    std::cout << "+---" << "+\n";
}

void GameBoard::PrintNumbers(int row)
{
    for (int i = 0; i < COLS - 1; ++i)
    {
        std::cout << "| " << translator[board[COLS * row + i]] << " ";
    }

    std::cout << "| " << translator[board[COLS * row + COLS - 1]] << " |\n";
}

void GameBoard::PrintColumnNumbers()
{
    for (int i = 1; i < COLS; ++i)
    {
        std::cout << "  " << i << " ";
    }

    std::cout << "  " << COLS << " \n";
}
