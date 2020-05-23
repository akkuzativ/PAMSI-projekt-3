#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "game.hpp"


class Renderer
{
    private:
        sf::Texture fieldSprites[6];

    public:
        bool loadTextures(std::string resourcesFolder);
        bool drawBoard(Board gameboard, sf::Window& window);
        bool highlightChosenPosition(Position chosenPosition);
};



#endif