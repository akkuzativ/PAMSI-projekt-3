#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../inc/player.hpp"



Position HumanPlayer::selectPiece(Board& gameboard)
{
    int row, column;
    do
    {
        std::cout << "wybierz pionek: ";
        std::cin >> row >> column;
    } while ((gameboard(row, column).type != color.first && gameboard(row, column).type != color.second) || row < 0 || row > 7 || column < 0 || column > 7 || gameboard(row, column).possibleMoves.empty());
    return {row, column};
}



Move HumanPlayer::selectMove(Board& gameboard, Position chosenPiece)
{
    bool possibleMoveNotSelected = true;
    Move chosenMove;
    int row, column;
    while(possibleMoveNotSelected)
    {
        std::cin >> row >> column;
        for (unsigned i = 0; i < gameboard(chosenPiece).possibleMoves.size(); i++)
        {
            if (gameboard(chosenPiece).possibleMoves[i].landingPosition == Position(row, column))
            {
                chosenMove = gameboard(chosenPiece).possibleMoves[i];
                possibleMoveNotSelected = false;
            }
        }
        
    }
    return chosenMove;
}



Position HumanPlayer::selectPiece(Board& gameboard, sf::RenderWindow& w)
{
    sf::Event e;
    int row = -1;
    int column = -1;
    do
    {
        w.pollEvent(e);
        if (e.type == sf::Event::MouseButtonPressed)
        {
            row = floor(sf::Mouse::getPosition(w).y/32);
            column = floor(sf::Mouse::getPosition(w).x/32);
        }
    } while ((gameboard(row, column).type != color.first && gameboard(row, column).type != color.second) || row < 0 || row > 7 || column < 0 || column > 7 || gameboard(row, column).possibleMoves.empty());
    return {row, column};
}



Move HumanPlayer::selectMove(Board& gameboard, Position chosenPiece, sf::RenderWindow& w)
{
    sf::Event e;
    bool possibleMoveNotSelected = true;
    Move chosenMove;
    int row = -1;
    int column = -1;
    while(possibleMoveNotSelected)
    {
        w.pollEvent(e);
        if (e.type == sf::Event::MouseButtonPressed)
        {
            row = floor(sf::Mouse::getPosition(w).y/32);
            column = floor(sf::Mouse::getPosition(w).x/32);
        }
        for (unsigned i = 0; i < gameboard(chosenPiece).possibleMoves.size(); i++)
        {
            if (gameboard(chosenPiece).possibleMoves[i].landingPosition == Position(row, column))
            {
                chosenMove = gameboard(chosenPiece).possibleMoves[i];
                possibleMoveNotSelected = false;
            }
        }   
    }
    return chosenMove;
}





void AIPlayer::minimax()
{

}


std::pair<Position, Move> AIPlayer::bestPieceAndMove(Board gameboard)
{
    std::vector<Position> usablePieces;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gameboard(i, j).type == color.first || gameboard(i, j).type == color.second)
            {
                if (!gameboard(i, j).possibleMoves.empty())
                {
                    usablePieces.emplace_back(Position(i, j));
                }     
            }
        }
    }
}