#pragma once

// Enum for representing grid squares.
enum gridMove : unsigned int 
{
    Empty,
    Player,
    Computer
};

// Enum for representing state of game.
enum gameStatus : unsigned int 
{
    Playing,
    PlayerWon,
    ComputerWon,
    Draw
};

