#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>

#include "game.hpp"


class Renderer
{
    private:
        sf::Texture fieldTextures[6];
        sf::Sprite fieldSprites[6];

    public:
        bool loadTextures();
        bool drawBoard(Board gameboard, sf::RenderWindow& window);
        bool highlightChosenPosition(Position chosenPosition);
};



#endif