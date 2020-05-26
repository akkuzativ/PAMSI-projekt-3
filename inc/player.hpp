#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "board.hpp"

class Player
{
    protected:
        std::pair<Board::FieldType, Board::FieldType> color;
        std::vector<Position> myPieces;

    public:
        Player(std::pair<Board::FieldType, Board::FieldType> constructorColor) {color = constructorColor;}; 
        void updateMyPieces(Board gameboard);
        Position choosePiece(Board gameboard, sf::RenderWindow& window);
        Move chooseMove(Position piece, Board gameboard, sf::RenderWindow& window);

};


class AI: public Player
{
    public:
        Move bestMove; ///bedzie dzialac jak zmienna globalna, dostosowywana w minimaxie !!!
        int minimax(Board gameboard, int depth, bool isMaxing);
};



#endif