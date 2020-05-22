#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

#include "../inc/game.hpp"





int main()
{
    Game g;
    do 
    {  
        g.draw();   
        g.turn();
    } while (g.redJumps != 12 || g.redJumps != 12);
            

    return 0;
}