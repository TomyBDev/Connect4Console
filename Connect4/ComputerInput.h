#ifndef COMPUTER_INPUT_H
#define COMPUTER_INPUT_H

#include "GridEnum.h"

class ComputerInput
{
public:
    /** Empty Constructor */
    ComputerInput(int numColumns, int numRows) : cols(numColumns), rows(numRows) {}

    /** Returns Computers Move */
    int GetInput(gridMove* board);

private:

    int minimax(gridMove* board, int depth, bool bMaximizing);

    int evaluateBoard(gridMove* board);

    bool IsTie(gridMove* board);

    bool EqualsFour(gridMove A, gridMove B, gridMove C, gridMove D);

    int cols, rows;
};
#endif