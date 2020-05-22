#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

#include "../inc/game.hpp"





int main()
{
    Game g;
    g.draw();
    do 
    {     
        g.turn();
        g.draw();
    } while (g.redJumps != 12 || g.redJumps != 12);
            

    return 0;
}