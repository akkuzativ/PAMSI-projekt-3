#include "../inc/player.hpp"



#include <cmath>
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