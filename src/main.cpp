#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>


#include "../inc/board.hpp"
#include "../inc/player.hpp"
#include "../inc/renderer.hpp"



std::ostream& operator << (std::ostream& out, Position p)
{
    out << p.row << " " << p.column;
    return out;
}



std::ostream& operator << (std::ostream& out, Move m)
{
    out << "source: " << m.source << "  landing: " << m.landing;
    if (m.type == Move::JUMP) out << "  jumped: " << m.jumpedPiece;
    return out;
}


Position getMouseInput(sf::RenderWindow& window)
{
    while (window.isOpen()) //main loop
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    return Position(floor(sf::Mouse::getPosition(window).y/32), floor(sf::Mouse::getPosition(window).x/32));
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {

                }
            }
        }
    }
    return Position(-1, -1);
}





void kingify(Board& gameboard)
{
    for (int i = 0; i < 8; i++)
    {
        if (gameboard(0, i) == Board::FieldType::WHITE) gameboard(0, i) = Board::FieldType::WHITEKING;
    }
    for (int i = 0; i < 8; i++)
    {
        if (gameboard(7, i) == Board::FieldType::RED) gameboard(7, i) = Board::FieldType::REDKING;
    }
}



void executeMove(Board& gameboard, Move chosenMove)
{
    if (chosenMove.type == Move::REGULAR)
    {
        gameboard.swapFields(chosenMove.source, chosenMove.landing);
    }
    if (chosenMove.type == Move::JUMP)
    {
        gameboard.swapFields(chosenMove.source, chosenMove.landing);
        gameboard.removeField(chosenMove.jumpedPiece);
    }
}



void turnProcedure(Board& gameboard, Player player, sf::RenderWindow& window)
{
    Position chosenPiece = player.choosePiece(gameboard, window);
    Move chosenMove = player.chooseMove(chosenPiece, gameboard, window);
    executeMove(gameboard, chosenMove);
    kingify(gameboard);
}



int main()
{
    sf::RenderWindow gameWindow(sf::VideoMode(256, 256), "projekt-3", sf::Style::Titlebar | sf::Style::Close);
    Board gameboard;
    Renderer renderer;
    Player player1({Board::FieldType::RED, Board::FieldType::REDKING});
    Player player2({Board::FieldType::WHITE, Board::FieldType::WHITEKING});
    renderer.loadTextures();
    gameWindow.setFramerateLimit(30);
    renderer.drawBoard(gameboard, gameWindow);
    gameWindow.display();
    while (gameWindow.isOpen()) //main loop
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gameWindow.close();
            }
        }
        turnProcedure(gameboard, player1, gameWindow);
        renderer.drawBoard(gameboard, gameWindow);
        gameWindow.display();
        turnProcedure(gameboard, player2, gameWindow);
        renderer.drawBoard(gameboard, gameWindow);
        gameWindow.display();
    }
}