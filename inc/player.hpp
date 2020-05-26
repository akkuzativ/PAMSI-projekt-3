#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"

class Player
{
    //protected:
    public:
        std::pair<Board::FieldType, Board::FieldType> color;
        std::vector<Position> myPieces;

    public:
        Player() {};
        Player(std::pair<Board::FieldType, Board::FieldType> constructorColor) {color = constructorColor;}; 
        void updateMyPieces(Board gameboard);

};


class AI: public Player
{
    public:
        AI() {};
        AI(std::pair<Board::FieldType, Board::FieldType> constructorColor) {color = constructorColor;};
        Move bestMove(Board gameboard, int depth, Player enemy);
        int minimax(Board gameboard, int depth, bool isMaxing, Player enemy);
        int evaluateScore(Board gameboard, Player enemy);
};



#endif