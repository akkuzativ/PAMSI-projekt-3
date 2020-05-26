#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>


#include "../inc/board.hpp"
#include "../inc/player.hpp"
#include "../inc/renderer.hpp"


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

int main()
{
    sf::RenderWindow gameWindow(sf::VideoMode(256, 256), "projekt-3", sf::Style::Titlebar | sf::Style::Close);
    Board gameboard;
    Renderer renderer;
    Player player1({Board::FieldType::RED, Board::FieldType::REDKING});
    AI player2({Board::FieldType::WHITE, Board::FieldType::WHITEKING});


    bool validPieceChosen = false;
    bool validMoveChosen = false;
    Position clickedTile;
    Position chosenPiece;
    Move chosenMove;


    renderer.loadTextures();
    gameWindow.setFramerateLimit(30);

    //gameboard(4, 3) = Board::FieldType::RED;

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
            if (event.type == sf::Event::MouseButtonPressed)
            {
                player1.updateMyPieces(gameboard);
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    clickedTile = Position(floor(event.mouseButton.y/32), floor(event.mouseButton.x/32));
                    for (std::vector<Position>::iterator it = player1.myPieces.begin(); it < player1.myPieces.end(); ++it)
                    {
                        if (*it == clickedTile)
                        {
                            chosenPiece = clickedTile;
                            validPieceChosen = true;
                        }
                    }
                    if (validPieceChosen)
                    {
                        std::vector<Move> possibleMoves = gameboard.getPossibleMoves(chosenPiece);
                        for (std::vector<Move>::iterator it = possibleMoves.begin(); it < possibleMoves.end(); ++it)
                        {
                            if (it->landing == clickedTile)
                            {
                                chosenMove = *it;
                                validMoveChosen = true;
                            }
                        }
                    }
                }
                if (validMoveChosen)
                {
                    executeMove(gameboard, chosenMove);
                    validPieceChosen = false;
                    validMoveChosen = false;
                    kingify(gameboard);
                    renderer.drawBoard(gameboard, gameWindow);
                    gameWindow.display();
                    executeMove(gameboard, player2.bestMove(gameboard, 4, player1));
                    kingify(gameboard);
                    renderer.drawBoard(gameboard, gameWindow);
                    gameWindow.display();
                }
            }
        }
    }
}