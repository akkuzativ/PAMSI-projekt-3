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
    std::cout << "wybierz ruch: ";
    int row, column;
    for (u_int i = 0; i < gameboard(chosenPiece.row, chosenPiece.column).possibleMoves.size(); i++)
    {
        std::cout << gameboard(chosenPiece.row, chosenPiece.column).possibleMoves[i].landingPosition.row << " " << gameboard(chosenPiece.row, chosenPiece.column).possibleMoves[i].landingPosition.column << "\n";
    }
    u_int moveNumber;
    do
    {
        std::cin >> moveNumber;
    } while (moveNumber > gameboard(chosenPiece.row, chosenPiece.column).possibleMoves.size() || moveNumber < 0);

    return gameboard(chosenPiece.row, chosenPiece.column).possibleMoves[moveNumber];
}