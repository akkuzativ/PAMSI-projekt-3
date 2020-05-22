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
    g.draw(); 
    std::cout << "\n==================\n\n";
    do 
    {  
          
        g.turn(user1);
        g.draw();  
        g.turn(user2);
        g.draw(); 
    } while (g.redJumps != 12 || g.redJumps != 12);
            

    return 0;
}