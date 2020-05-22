#ifndef GAME_HPP
#define GAME_HPP


#include "board.hpp"



class Game
{
    //private:
    public:
        Board gameboard;
        std::pair<Field::Type, Field::Type> currentTurnPlayer;
        int redJumps;
        int whiteJumps;
        //std::vector<Position> redPieces;
        //std::vector<Position> whitePieces;
    public:
        Game() { currentTurnPlayer = {Field::WHITE, Field::WHITEKING}; };
        void getPossibleMoves(Position piece);
        void lookForAdditionalJumps(Position piece);
        void turn();
        void draw();



};



#endif