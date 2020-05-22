#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

#include "../inc/game.hpp"





int main()
{
    HumanPlayer user1;
    HumanPlayer user2;
    user1.color = {Field::WHITE, Field::WHITEKING};
    user2.color = {Field::RED, Field::REDKING};
    Game g;
    std::cout << "\n==================\n\n";
    do 
    {  
        if (g.redJumps != 12 && g.whiteJumps != 12)
        {
            g.turn(user1);
            g.draw();
        }
        if (g.redJumps != 12 && g.whiteJumps != 12)
        {
            g.turn(user2);
            g.draw();
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