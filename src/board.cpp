#include "../inc/board.hh"



std::pair<Field::Type, Field::Type> Field::getEnemy(Type type)
{
    if (type == RED || type == RED)
    {
        return {WHITE, WHITEKING};
    }
    else
    {
        return {RED, REDKING};
    } 
}



Board::Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i+j)%2 == 0)
            {
                _board[i][j].type = Field::INVALID;
            }
            else
            {
                if (i < 3)
                {
                    _board[i][j].type = Field::RED;
                }
                else if (i > 4)
                {
                    _board[i][j].type = Field::WHITE;
                }
                else
                {
                    _board[i][j].type = Field::FREE;
                }
            }
            _board[i][j].positionOnBoard = {i, j};
        }
    }
}



bool Board::checkRegularMovePotential(Position position)
{
    if (position.row < 0 || position.row > 7 || position.column < 0 || position.column > 7)
    {
        return false;
    }
    if (_board[position.row][position.column].type != Field::FREE)
    {
        return false;
    }


    return true;
}



bool Board::checkJumpPotential(Position pieceToBeJumped, Position landingPosition, Field::Type currentTurn)
{
    if (pieceToBeJumped.row < 0 || pieceToBeJumped.row > 7 || pieceToBeJumped.column < 0 || pieceToBeJumped.column > 7)
    {
        return false;
    }

    if (landingPosition.row < 0 || landingPosition.row > 7 || landingPosition.column < 0 || landingPosition.column > 7)
    {
        return false;
    }

    if (_board[pieceToBeJumped.row][pieceToBeJumped.column].type != Field::getEnemy(currentTurn).first || _board[pieceToBeJumped.row][pieceToBeJumped.column].type != Field::getEnemy(currentTurn).second)
    {
        return false;
    }
    
    if (_board[landingPosition.row][landingPosition.column].type != Field::FREE)
    {
        return false;
    }

    
    return true;
}



// do przeniesienia do klasy Game (narazie nie istnieje)

void getPossibleMoves(Position piece)
{
    switch(board[piece.row][piece.column].type)
    {
        case Field::RED:
            //check jump potential (r-1, c+1, r-2, c+2)
            //check jump potential (r-1, c-1, r-2, c-2)
            //check regular move potential (r-1, c-1)
            //check regular move potential (r-1, c+1) 
            break;
        case Field::WHITE:
            //check jump potential (r+1, c+1, r+2, c+2)
            //check jump potential (r+1, c-1, r+2, c-2)
            //check regular move potential (r-1, c-1)
            //check regular move potential (r-1, c+1) 
            break;
        case Field::REDKING: case Field::WHITEKING:
            // ??? 
            break;
    }
}