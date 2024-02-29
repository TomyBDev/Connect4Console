#include "Player.h"

#include <iostream>

// Gets the players input for their move.
int PlayerInput::GetInput()
{
    int input = 0;

    // Loops until valid input is received.
    while (true)
    {
        std::cout << "Enter your move (1-7): ";
        std::cin >> input;

        if (input >= 1 && input <= cols)
            break;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input - ";
    }
    
    return (input-1);
}
