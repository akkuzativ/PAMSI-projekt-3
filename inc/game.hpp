#ifndef GAME_HPP
#define GAME_HPP


#include "board.hpp"
#include "player.hpp"



class Game
{
    //private:
    public:
        Board gameboard;
        int redJumps;
        int whiteJumps;
        bool tested;
        //std::vector<Position> redPieces;
        //std::vector<Position> whitePieces;
    public:
        void getPossibleMoves(Position piece);
        void initializePossibleMovesForPlayersPieces(Player& player);
        void lookForAdditionalJumps(Position piece);
        void TurnIntoKings();
        void executeSelectedMove(Move move, Position chosenPiece, Player& player);
        void turn(Player& player);
        void draw();
        void customChange(int r, int c, Field::Type t) 
        { gameboard(r, c).type = t; };



};



#endif