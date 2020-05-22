#include <iostream>

#include "../inc/player.hpp"


Position HumanPlayer::selectPiece(Board gameboard)
{
    int row, column;
    do
    {
        std::cout << "wybierz pionek: ";
        std::cin >> row >> column;
    } while ((gameboard(row, column).type != color.first && gameboard(row, column).type != color.second) || row < 0 || row > 7 || column < 0 || column > 7 || gameboard(row, column).possibleMoves.empty());
    return {row, column};
}

Move HumanPlayer::selectMove(Board gameboard, Position chosenPiece)
{
    std::cout << "wybierz miejsce na ktore chcesz polozyc pionek: ";
    bool possibleMoveNotSelected = true;
    Move chosenMove;
    int row, column;
    while(possibleMoveNotSelected)
    {
        std::cin >> row >> column;
        for (unsigned i = 0; i < gameboard(chosenPiece.row, chosenPiece.column).possibleMoves.size(); i++)
        {
            if (gameboard(chosenPiece.row, chosenPiece.column).possibleMoves[i].landingPosition == Position(row, column))
            {
                chosenMove = gameboard(chosenPiece.row, chosenPiece.column).possibleMoves[i];
                possibleMoveNotSelected = false;
            }
        }
        
    }
    return chosenMove;
}