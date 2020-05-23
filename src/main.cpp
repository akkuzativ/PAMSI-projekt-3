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
    sf::RenderWindow w(sf::VideoMode(256, 256), "projekt-3", sf::Style::Titlebar | sf::Style::Close);
    w.setFramerateLimit(30);
    if (r.loadTextures() == false)
    {
        std::cout << "(!) Nie udalo sie wczytac tekstur" << std::endl;
    }
    r.drawBoard(g.gameboard, w);
    w.display();
    sf::Event event;
    do 
    {  
        w.pollEvent(event);
        if (g.redJumps != 12 && g.whiteJumps != 12)
        {
            std::cout << "Tura bialego" << std::endl;
            g.turn(user1, w);
            g.draw();
            w.clear();
            r.drawBoard(g.gameboard, w);
            w.display();
        }
        if (g.redJumps != 12 && g.whiteJumps != 12)
        {
            std::cout << "Tura czerwonego" << std::endl;
            g.turn(user2, w);
            g.draw();
            w.clear();
            r.drawBoard(g.gameboard, w);
            w.display();
        }
    } while (g.redJumps != 12 && g.whiteJumps != 12);
    if (g.redJumps == 12)
    {
        std::cout << "Czerwony wygrywa" << std::endl;
    }
    else
    {
        std::cout << "Bialy wygrywa" << std::endl;
    }
            

    return 0;
}