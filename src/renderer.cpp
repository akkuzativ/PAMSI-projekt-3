#include "../inc/renderer.hpp"


bool Renderer::loadTextures()
{
    if (!fieldTextures[0].loadFromFile("resources/invalid.bmp", sf::IntRect(0, 0, 32, 32)))
    {
        return false;
    }
    if (fieldTextures[1].loadFromFile("resources/free.bmp", sf::IntRect(0, 0, 32, 32)))
    {
        return false;
    }
    if (fieldTextures[2].loadFromFile("resources/red.bmp", sf::IntRect(0, 0, 32, 32)))
    {
        return false;
    }
    if (fieldTextures[3].loadFromFile("resources/white.bmp", sf::IntRect(0, 0, 32, 32)))
    {
        return false;
    }
    if (fieldTextures[4].loadFromFile("resources/redking.bmp", sf::IntRect(0, 0, 32, 32)))
    {
        return false;
    }
    if (fieldTextures[5].loadFromFile("resources/whiteking.bmp", sf::IntRect(0, 0, 32, 32)))
    {
        return false;
    }



    for (int i = 0; i < 6; i++)
    {
        fieldSprites[i].setTexture(fieldTextures[i]);
    }



    return true;
}


bool Renderer::drawBoard(Board gameboard, sf::RenderWindow& window)

{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            switch (gameboard(i, j).type)
            {
            case Field::INVALID:
                fieldSprites[0].setPosition(32*i, 32*j);
                window.draw(fieldSprites[0]);
                break;
            case Field::FREE:
                fieldSprites[0].setPosition(32*i, 32*j);
                window.draw(fieldSprites[1]);
                break;
            case Field::RED:
                fieldSprites[0].setPosition(32*i, 32*j);
                window.draw(fieldSprites[2]);
                break;
            case Field::WHITE:
              fieldSprites[0].setPosition(32*i, 32*j);
                window.draw(fieldSprites[3]);
                break;    
            case Field::REDKING:
                fieldSprites[0].setPosition(32*i, 32*j);
                window.draw(fieldSprites[4]);
                break;
            case Field::WHITEKING:
                fieldSprites[0].setPosition(32*i, 32*j);
                window.draw(fieldSprites[5]);
                break;
            }
        }
    }
}


bool highlightChosenPosition(Position chosenPosition)
{

}