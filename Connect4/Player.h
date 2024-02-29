#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

class PlayerInput
{
public:
    /** Empty Constructor */
    PlayerInput(int numColumns) : cols(numColumns) {}

    /** Returns Computers Move */
    int GetInput();

private:
    int cols;
};
#endif