#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>





int main()
{
    sf::RenderWindow window(sf::VideoMode(256, 256), "projekt-3");
    window.setFramerateLimit(30);
    sf::Texture textures[6];
    sf::Sprite sprites[6];
    textures[0].loadFromFile("resources/invalid.bmp");
    textures[1].loadFromFile("resources/free.bmp");
    textures[2].loadFromFile("resources/red.bmp");
    textures[3].loadFromFile("resources/redking.bmp");
    textures[4].loadFromFile("resources/white.bmp");
    textures[5].loadFromFile("resources/whiteking.bmp");


    sf::Clock Clock;

    for (int i = 0; i < 6; i++)
    {
        sprites[i].setTexture(textures[i]);
    }  
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                window.close();
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        for(int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i+j)%2 == 0)
                {
                    window.draw(sprites[0]);
                    sprites[0].setPosition(j*32, i*32);
                }
                else
                {
                    if (i < 3)
                    {
                        window.draw(sprites[2]);
                        sprites[2].setPosition(j*32, i*32);
                    }
                    else if (i > 4)
                    {
                        window.draw(sprites[4]);
                        sprites[4].setPosition(j*32, i*32);
                    }
                    else
                    {
                        window.draw(sprites[1]);
                        sprites[1].setPosition(j*32, i*32);
                    }
                }        
            }
            
        }
        window.display();
    }
    return 0;
}