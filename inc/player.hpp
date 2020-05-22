#ifndef PLAYER_HH
#define PLAYER_HH

#include "board.hpp"

class Player
{
    public:
        int numberOfKings;
        int numberOfJumps;
        std::pair<Field::Type, Field::Type> color;
        virtual Position selectPiece() = 0;
        virtual Move selectMove(Position selectedPiece) = 0;
};


class HumanPlayer: public Player
{

};


class AIPlayer: public Player
{

};


#endif