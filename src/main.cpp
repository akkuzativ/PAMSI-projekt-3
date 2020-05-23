#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

#include "../inc/game.hpp"
#include "../inc/renderer.hpp"




int main()
{
    
    HumanPlayer user1;
    HumanPlayer user2;
    Renderer r;
    user1.color = {Field::WHITE, Field::WHITEKING};
    user2.color = {Field::RED, Field::REDKING};
    Game g;
    g.draw();
    sf::RenderWindow w(sf::VideoMode(256, 256), "projekt-3");
    w.setFramerateLimit(30);
    if (r.loadTextures() == false)
    {
        std::cout << "(!) Nie udalo sie wczytac tekstur" << std::endl;
    }
    r.drawBoard(g.gameboard, w);
    w.display();
    std::cout << "\n==================\n\n";
    do 
    {  
        if (g.redJumps != 12 && g.whiteJumps != 12)
        {
            g.turn(user1);
            g.draw();
            r.drawBoard(g.gameboard, w);
            w.display();
        }
        if (g.redJumps != 12 && g.whiteJumps != 12)
        {
            g.turn(user2);
            g.draw();
            r.drawBoard(g.gameboard, w);
            w.display();
        }
    } while (g.redJumps != 12 && g.whiteJumps != 12);
    if (g.redJumps == 12)
    {
        std::cout << "red wins" << std::endl;
    }
    else
    {
        std::cout << "white wins" << std::endl;
    }
            

    return 0;
}