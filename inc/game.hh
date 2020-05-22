#ifndef GAME_HPP
#define GAME_HPP


#include "board.hh"



class Game
{
    private:
        Board gameboard;
        //std::vector<Position> redPieces;
        //std::vector<Position> whitePieces;
    public:
        void getPossibleMoves(Position piece);
        void lookForAdditionalJumps(Position piece);
        void removeJumpedPieces(std::vector<Position> jumpedPiecesInCurrentTurn);
        void turn();
};



#endif