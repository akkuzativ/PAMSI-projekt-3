#ifndef PLAYER_HH
#define PLAYER_HH

#include "board.hpp"

class Player
{
    public:
        int numberOfKings;
        int numberOfJumps;
        std::pair<Field::Type, Field::Type> color;
        virtual Position selectPiece(Board gameboard) = 0;
        virtual Move selectMove(Board gameboard, Position selectedPiece) = 0;
};


class HumanPlayer: public Player
{
    Position selectPiece(Board gameboard);
    Move selectMove(Board gameboard, Position selectedPiece);
};


class AIPlayer: public Player
{
    Position selectPiece(Board gameboard) {};
    Move selectMove(Board gameboard, Position selectedPiece) {};
};


#endif