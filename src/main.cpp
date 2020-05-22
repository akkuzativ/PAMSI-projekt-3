#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

#include "../inc/game.hpp"


class GameRenderer
{
    public:
        sf::Texture textures[6];
        sf::Sprite sprites[6];    
        GameRenderer();
        void DrawGame(Game g);
};

GameRenderer::GameRenderer()
{
    textures[0].loadFromFile("resources/invalid.bmp");
    textures[1].loadFromFile("resources/free.bmp");
    textures[2].loadFromFile("resources/red.bmp");
    textures[3].loadFromFile("resources/redking.bmp");
    textures[4].loadFromFile("resources/white.bmp");
    textures[5].loadFromFile("resources/whiteking.bmp");


    for (int i = 0; i < 6; i++)
    {
        sprites[i].setTexture(textures[i]);
    }  
}

void GameRenderer::DrawGame(Game g)
{
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

        }
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(256, 256), "projekt-3");
    window.setFramerateLimit(30);

    GameRenderer renderer;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.display();
    }
    return 0;
}