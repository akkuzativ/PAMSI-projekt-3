#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "board.hpp"
#include "player.hpp"



class Game
{
    //private:
    public:
        Board gameboard;
        int redJumps;
        int whiteJumps;

    public:
        Game() {redJumps = 0; whiteJumps = 0;};
        void findAllMoves(Position piece);
        void initializePossibleMovesForPlayersPieces(Player& player);
        void findJumps(Position piece);
        void turnIntoKings();
        Position executeSelectedMove(Move chosenMove, Position chosenPiece, Player& player, sf::RenderWindow& w);
        void turn(Player& player);
        void turn(Player& player, sf::RenderWindow& w);
        void draw();
        void customChange(int r, int c, Field::Type t) 
        { gameboard(r, c).type = t; };


        friend class Renderer;
};

#endif