#include "ComputerInput.h"

#include <algorithm>
#include <climits>
#include <fenv.h>

int ComputerInput::GetInput(gridMove* board)
{
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < cols; ++i)
    {
        if (board[i] != Empty)
            continue;

        for (int j = rows - 1; j >= 0; j--)
        {
            if (!board[cols * j + i])
            {
                board[cols * j + i] = Computer;

                int evaluation = minimax(board, 0, false);

                board[cols * j + i] = Empty;

                if (evaluation > bestVal)
                {
                    bestVal = evaluation;
                    bestMove = i;
                }
                
                break;
            }
        }
    }
    
    return bestMove;
}

int ComputerInput::minimax(gridMove* board, int depth, bool bMaximizing)
{
    int evaluation = evaluateBoard(board);
    
    if (evaluation != 0)
        return evaluation;

    if (IsTie(board))
        return 0;

    if (depth > 7)
        return 0;

    if (bMaximizing)
    {
        int bestVal = INT_MIN;
        
        for (int i = 0; i < cols; ++i)
        {
            if (board[i] != Empty)
                continue;

            for (int j = rows - 1; j >= 0; j--)
            {
                if (!board[cols * j + i])
                {
                    board[cols * j + i] = Computer;
                    
                    bestVal = std::max(bestVal, minimax(board, depth+1, false));

                    board[cols * j + i] = Empty;

                    break;
                }
            }
        }
        return bestVal;
    }

    int bestVal = INT_MAX;

    for (int i = 0; i < cols; ++i)
    {
        if (board[i] != Empty)
            continue;

        for (int j = rows - 1; j >= 0; j--)
        {
            if (!board[cols * j + i])
            {
                board[cols * j + i] = Player;
                
                bestVal = std::min(bestVal, minimax(board, depth+1, true));

                board[cols * j + i] = Empty;

                break;
            }
        }
    }

    return bestVal;
}

int ComputerInput::evaluateBoard(gridMove* board)
{
    // Horizontal Check
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j <= cols - 4; ++j)
        {
            if (EqualsFour(board[i*cols+(j + 0)], board[i*cols+(j + 1)], board[i*cols+(j + 2)], board[i*cols+(j + 3)]))
            {
                if (board[i*cols+(j + 0)] == Player)
                    return -10;
                return 10;
            }
        }
    }

    // Vertical Check
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j <= rows - 4; ++j)
        {
            if (EqualsFour(board[(j+0)*cols+i], board[(j+1)*cols+i], board[(j+2)*cols+i], board[(j+3)*cols+i]))
            {
                if (board[(j+0)*cols+i] == Player)
                    return -10;
                return 10;
            }
        }
    }

    // Diagonal Check

    /*if (EqualsThree(board[0], board[4], board[8]))
    {
        if (board[4] == Player)
            return -10;
        return 10;
    }
    else if (EqualsThree(board[2], board[4], board[6]))
    {
        if (board[4] == Player)
            return -10;
        return 10;
    }*/

    return 0;
}

bool ComputerInput::IsTie(gridMove* board)
{
    bool bIsTie = true;
    
    for (int i = 0; i < cols; ++i)
    {
        if (board[i] == Empty)
            bIsTie = false;
    }

    return  bIsTie;
}

bool ComputerInput::EqualsFour(gridMove A, gridMove B, gridMove C, gridMove D)
{
    return (A == B && B == C && C == D && A != Empty);
}
