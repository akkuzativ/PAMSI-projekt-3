#include "../inc/player.hpp"




#include <iostream>

std::ostream& operator<<(std::ostream& out, Position p);
std::ostream& operator<<(std::ostream& out, Move m);
Position getMouseInput(sf::RenderWindow& window);




void Player::updateMyPieces(Board gameboard)
{
    myPieces.clear();
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gameboard(i, j) == color.first || gameboard(i, j) == color.second)
            {
                myPieces.emplace_back(Position(i, j));
            }
        }
    }
}



Position Player::choosePiece(Board gameboard, sf::RenderWindow& window)
{
    updateMyPieces(gameboard);
    Position chosenPiece;
    std::cout << "Wybierz pionek..." << std::endl;
    do
    {
        chosenPiece = getMouseInput(window);
        for (std::vector<Position>::iterator it = myPieces.begin(); it < myPieces.end(); ++it)
        {
            if (*it == chosenPiece)
            {
                return *it;
            }
        }
    } while (chosenPiece.row != -9 && chosenPiece.column != -9);
    return Position({-9,-9});
}



Move Player::chooseMove(Position Piece, Board gameboard, sf::RenderWindow& window)
{
    std::vector<Move> possibleMoves = gameboard.getPossibleMoves(Piece);
    for (std::vector<Move>::iterator it = possibleMoves.begin(); it < possibleMoves.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    Position chosenLanding;
    Move chosenMove;
    std::cout << "Wybierz gdzie go umiescic..." << std::endl;
    do
    {
        chosenLanding = getMouseInput(window);
        for (std::vector<Move>::iterator it = possibleMoves.begin(); it < possibleMoves.end(); ++it)
        {
            if (it->landing == chosenLanding)
            {
                return *it;
            }
        }
    } while (chosenLanding.row != -9 && chosenLanding.column != -9);
    return Move({-9,-9},{-9,-9});
}