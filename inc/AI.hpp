#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"



class AI: public Player
{
    public:
        AI() {};
        AI(std::pair<Board::FieldType, Board::FieldType> constructorColor) {color = constructorColor;};
        int evaluateScore(Board gameboard, Player enemy);
        int minimax(Board gameboard, int depth, bool isMaxing, Player enemy);
        Move bestMove(Board gameboard, int depth, Player enemy);     
};

#endif
