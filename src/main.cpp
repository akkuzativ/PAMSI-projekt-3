#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

#include "../inc/board.hpp"
#include "../inc/player.hpp"
#include "../inc/AI.hpp"
#include "../inc/renderer.hpp"



bool gameover(Player player, AI ai, Board gameboard)
{
    player.updateMyPieces(gameboard);
    if (player.myPieces.empty())
    {
        std::cout << "Koniec gry,\nWygrywa komputer\nPowod: Zbicie wszystkich pionkow gracza\n";
        return true;
    }
    ai.updateMyPieces(gameboard);
    if (ai.myPieces.empty())
    {
        std::cout << "Koniec gry,\nWygrywa gracz\nPowod: Zbicie wszystkich pionkow komputera\n";
        return true;
    }
    std::vector<Move> playerMoves;
    for (std::vector<Position>::iterator it = player.myPieces.begin(); it < player.myPieces.end(); ++it)
    {
        std::vector<Move> moves = gameboard.getPossibleMoves(*it);
        for (std::vector<Move>::iterator itm = moves.begin(); itm < moves.end(); ++itm)
        {
            playerMoves.emplace_back(*itm);
        }
    }
    if (playerMoves.empty())
    {
        std::cout << "Koniec gry,\nWygrywa komputer\nPowod: Zablokowanie wykonywania ruchow graczowi\n";
        return true;
    }
    std::vector<Move> aiMoves;
    for (std::vector<Position>::iterator it = ai.myPieces.begin(); it < ai.myPieces.end(); ++it)
    {
        std::vector<Move> moves = gameboard.getPossibleMoves(*it);
        for (std::vector<Move>::iterator itm = moves.begin(); itm < moves.end(); ++itm)
        {
            aiMoves.emplace_back(*itm);
        }
    }
    if(aiMoves.empty())
    {
        std::cout << "Koniec gry,\nWygrywa gracz\nPowod: Zablokowanie wykonywania ruchow komputerowi\n";
        return true;
    }
    return false;
}



int main()
{
    sf::RenderWindow gameWindow(sf::VideoMode(256, 256), "projekt-3", sf::Style::Titlebar | sf::Style::Close);
    Board gameboard;
    Renderer renderer;
    Player player1({Board::FieldType::WHITE, Board::FieldType::WHITEKING});
    AI player2({Board::FieldType::RED, Board::FieldType::REDKING});
    bool validPieceChosen = false;
    bool validMoveChosen = false;
    Position clickedTile;
    Position chosenPiece;
    Move chosenMove;
    renderer.loadTextures();
    gameWindow.setFramerateLimit(30);
    renderer.drawBoard(gameboard, gameWindow);
    gameWindow.display();
    std::cout << "Kolor gracza: bialy; Kolor komputera: czerwony\n\n";
    std::cout << "Tura gracza...\n";
    while (gameWindow.isOpen())
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || gameover(player1, player2, gameboard))
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
                    gameboard.executeMove(chosenMove);
                    validPieceChosen = false;
                    validMoveChosen = false;
                    gameboard.kingify();
                    renderer.drawBoard(gameboard, gameWindow);
                    gameWindow.display();
                    std::cout << "Tura komputera...\n";
                    gameboard.executeMove(player2.bestMove(gameboard, 4, player1));
                    gameboard.kingify();
                    renderer.drawBoard(gameboard, gameWindow);
                    gameWindow.display();
                    std::cout << "Tura gracza...\n";
                }
            }
        }
    }
}