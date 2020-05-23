#include "../inc/renderer.hpp"


bool Renderer::loadTextures(std::string resourcesFolder)
{
    if (!fieldSprites[0].loadFromFile(resourcesFolder + "invalid.bmp"))
    {
        return false;
    }
    if (fieldSprites[1].loadFromFile(resourcesFolder + "free.bmp"))
    {
        return false;
    }
    if (fieldSprites[2].loadFromFile(resourcesFolder + "red.bmp"))
    {
        return false;
    }
    if (fieldSprites[3].loadFromFile(resourcesFolder + "white.bmp"))
    {
        return false;
    }
    if (fieldSprites[4].loadFromFile(resourcesFolder + "redking.bmp"))
    {
        return false;
    }
    if (fieldSprites[5].loadFromFile(resourcesFolder + "whiteking.bmp"))
    {
        return false;
    }

    return true;
}


bool drawBoard(Board gameboard, sf::Window& window)
{

}

bool highlightChosenPosition(Position chosenPosition)
{

}