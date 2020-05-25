#ifndef PLAYER_HH
#define PLAYER_HH

#include "board.hpp"



class Player
{
    public:
        int numberOfKings;
        int numberOfJumps;
        std::pair<Field::Type, Field::Type> color;
        virtual Position selectPiece(Board& gameboard) = 0;
        virtual Move selectMove(Board& gameboard, Position selectedPiece) = 0;
        virtual Position selectPiece(Board& gameboard, sf::RenderWindow& w) = 0;
        virtual Move selectMove(Board& gameboard, Position selectedPiece, sf::RenderWindow& w) = 0;
};



class HumanPlayer: public Player
{
    public:
        Position selectPiece(Board& gameboard);
        Move selectMove(Board& gameboard, Position selectedPiece);
        Position selectPiece(Board& gameboard, sf::RenderWindow& w);
        Move selectMove(Board& gameboard, Position selectedPiece, sf::RenderWindow& w);
};



class AIPlayer: public Player
{
    public:
        void minimax();
        std::pair<Position, Move> bestPieceAndMove(Board gameboard);



        Position selectPiece(Board& gameboard) {};
        Move selectMove(Board& gameboard, Position selectedPiece) {};
};


#endif