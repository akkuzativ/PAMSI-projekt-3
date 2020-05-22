#ifndef GAME_HPP
#define GAME_HPP


#include "board.hpp"



class Game
{
    //private:
    public:
        Board gameboard;
        Field::Type currentTurn;
        int redJumps;
        int whiteJumps;
        //std::vector<Position> redPieces;
        //std::vector<Position> whitePieces;
    public:
        void getPossibleMoves(Position piece);
        void lookForAdditionalJumps(Position piece);
        void turn();
        void draw();



};



#endif