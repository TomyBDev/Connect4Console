// Custom classes.
#include "GameBoard.h"
#include "Player.h"
#include "ComputerInput.h"

// Input + Output.
#include <iostream>

// Pre-declaration.
bool ShouldComputerGoFirst();

int main(int argc, char* argv[])
{
    // Create Objects.
    GameBoard board;
    PlayerInput player(board.GetCols());
    ComputerInput computer(board.GetCols(), board.GetRows());

    // Asks player who goes first.
    if (ShouldComputerGoFirst()) // If computer goes first, make their move.
        board.PlayMove(computer.GetInput(board.getBoard()), Computer);

    // Loops player and computers turns displaying in console.
    while (true)
    {
        // Display Game Board.
        board.DisplayGameBoard();

        // Keep trying to get player input until its valid the register the move with the board.
        while (!board.PlayMove(player.GetInput())) {}

        // Break early if win was detected.
        if (board.GetGameState() != Playing) {break;}

        // Play 
        board.PlayMove(computer.GetInput(board.getBoard()), Computer);

        // Break early if win or draw was detected.
        if (board.GetGameState() != Playing) {break;}

        // Clear console and bring cursor to top left
        system("CLS");
    }

    // GG - you probably Lost or Draw.
    char input;
    std::cin >> input;
    return 0;
}

// Returns true if user doesn't want to go first.
bool ShouldComputerGoFirst()
{
    // Ask if player wants to go first.
    std::cout << "Do you want to go first?\n(Y / N): ";

    // Get player input.
    char input;
    std::cin >> input;

    // Clear console.
    system("CLS");

    // If player wants to go first, return false.
    if (input == 'Y')
        return false;

    // Player doesn't want to go first, return true.
    return true;
}
