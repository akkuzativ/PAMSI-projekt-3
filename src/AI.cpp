#include "../inc/AI.hpp"



int AI::evaluateScore(Board gameboard, Player enemy)
{
    int score = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gameboard(i, j) == color.first)
            {
                score = score + 1;
            }
            if (gameboard(i, j) == color.second)
            {
                score = score + 3;
            }
            if (gameboard(i, j) == enemy.color.first)
            {
                score = score - 1;
            }
            if (gameboard(i, j) == enemy.color.second)
            {
                score = score - 3;
            }
        }
    }
    return score;
}



int AI::minimax(Board gameboard, int depth, bool isMaxing, Player enemy)
{
    if (depth <= 0)
    {
        return evaluateScore(gameboard, enemy);
    }
    if (isMaxing)
    {
        updateMyPieces(gameboard);
        int bestScore = -1000;
        std::vector<Move> possibleMoves;
        for (std::vector<Position>::iterator it = myPieces.begin(); it < myPieces.end(); ++it)
        {
            std::vector<Move> moves = gameboard.getPossibleMoves(*it);
            for (std::vector<Move>::iterator itm = moves.begin(); itm < moves.end(); ++itm)
            {
                possibleMoves.emplace_back(*itm);
            }
        }
        for (std::vector<Move>::iterator it = possibleMoves.begin(); it < possibleMoves.end(); ++it)
        {
            Board gameboardClone = gameboard;
            gameboardClone.executeMove(*it);
            gameboardClone.kingify();
            int currentScore = minimax(gameboardClone, depth-1, !isMaxing, enemy);
            if (currentScore > bestScore)
            {
                bestScore = currentScore;
            }
        }
        return bestScore;
    }
    else
    {
        enemy.updateMyPieces(gameboard);
        int bestScore = 1000;
        std::vector<Move> possibleMoves;
        for (std::vector<Position>::iterator it = enemy.myPieces.begin(); it < enemy.myPieces.end(); ++it)
        {
            std::vector<Move> moves = gameboard.getPossibleMoves(*it);
            for (std::vector<Move>::iterator itm = moves.begin(); itm < moves.end(); ++itm)
            {
                possibleMoves.emplace_back(*itm);
            }
        }
        for (std::vector<Move>::iterator it = possibleMoves.begin(); it < possibleMoves.end(); ++it)
        {
            Board gameboardClone = gameboard;
            gameboardClone.executeMove(*it);
            gameboardClone.kingify();
            int currentScore = minimax(gameboardClone, depth-1, !isMaxing, enemy);
            if (currentScore <= bestScore)
            {
                bestScore = currentScore;
            }   
        }
        return bestScore;  
    }
}



Move AI::bestMove(Board gameboard, int depth, Player enemy)
{
    updateMyPieces(gameboard);
    int bestScore = -1000;
    Move bestMove;
    std::vector<Move> possibleMoves;
    for (std::vector<Position>::iterator it = myPieces.begin(); it < myPieces.end(); ++it)
    {
        std::vector<Move> moves = gameboard.getPossibleMoves(*it);
        for (std::vector<Move>::iterator itm = moves.begin(); itm < moves.end(); ++itm)
        {
            possibleMoves.emplace_back(*itm);
        }
    }
    for (std::vector<Move>::iterator it = possibleMoves.begin(); it < possibleMoves.end(); ++it)
    {
        Board gameboardClone = gameboard;
        gameboardClone.executeMove(*it);
        gameboardClone.kingify();
        int currentScore = minimax(gameboardClone, depth-1, false, enemy);
        if (currentScore > bestScore)
        {
            bestScore = currentScore;
            bestMove = *it;
        }
    }
    return bestMove;
}