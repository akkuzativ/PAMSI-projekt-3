#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "board.hpp"



class Player
{
    public:
        std::pair<Board::FieldType, Board::FieldType> color;
        std::vector<Position> myPieces;

        Player() {};
        Player(std::pair<Board::FieldType, Board::FieldType> constructorColor) {color = constructorColor;}; 
        void updateMyPieces(Board gameboard);

};

#endif