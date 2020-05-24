#include <iostream>

#include "../inc/game.hpp"



void Game::findJumps(Position piece)
{
    gameboard(piece).possibleMoves.clear();
    switch(gameboard(piece).type)
    {
        case Field::RED:
            if (gameboard.checkJumpPotential(piece.returnModified(+1, +1), piece.returnModified(+2, +2), Field::RED))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(+1, +1), piece.returnModified(+2, +2)));
            }
            if (gameboard.checkJumpPotential(piece.returnModified(+1, -1), piece.returnModified(+2, -2), Field::RED))
            {
                gameboard(piece).possibleMoves.push_back(Move(piece.returnModified(+1, -1), piece.returnModified(+2, -2)));
            }
            break;
        case Field::WHITE:
            if (gameboard.checkJumpPotential(piece.returnModified(-1, +1), piece.returnModified(-2, +2), Field::WHITE))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(-1, +1), piece.returnModified(-2, +2)));
            }
            if (gameboard.checkJumpPotential(piece.returnModified(-1, -1), piece.returnModified(-2, -2), Field::WHITE))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(-1, -1), piece.returnModified(-2, -2)));
            }
            break;
        case Field::REDKING: case Field::WHITEKING:
            if (gameboard.checkJumpPotential(piece.returnModified(+1, +1), piece.returnModified(+2, +2), gameboard(piece).type))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(+1, +1), piece.returnModified(+2, +2)));
            }
            if (gameboard.checkJumpPotential(piece.returnModified(+1, -1), piece.returnModified(+2, -2), gameboard(piece).type))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(+1, -1), piece.returnModified(+2, -2)));
            }
            if (gameboard.checkJumpPotential(piece.returnModified(-1, +1), piece.returnModified(-2, +2), gameboard(piece).type))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(-1, +1), piece.returnModified(-2, +2)));
            }
            if (gameboard.checkJumpPotential(piece.returnModified(-1, -1), piece.returnModified(-2, -2), gameboard(piece).type))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(-1, -1), piece.returnModified(-2, -2)));
            }
            break;
        default:
            break;
    }
}



void Game::findAllMoves(Position piece)
{
    gameboard(piece).possibleMoves.clear();
    findJumps(piece);
    switch(gameboard(piece).type)
    {
        case Field::RED:
            if (gameboard.checkRegularMovePotential(piece.returnModified(+1,+1)))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(+1,+1)));
            }
            if (gameboard.checkRegularMovePotential(piece.returnModified(+1,-1)))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(+1,-1)));
            }
            break;
        case Field::WHITE:
            if (gameboard.checkRegularMovePotential(piece.returnModified(-1,+1)))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(-1,+1)));
            }
            if (gameboard.checkRegularMovePotential(piece.returnModified(-1,-1)))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(-1,-1)));
            }
            break;
        case Field::REDKING: case Field::WHITEKING:
            if (gameboard.checkRegularMovePotential(piece.returnModified(+1,+1)))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(+1,+1)));
            }
            if (gameboard.checkRegularMovePotential(piece.returnModified(+1,-1)))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(+1,-1)));
            }
            if (gameboard.checkRegularMovePotential(piece.returnModified(-1,+1)))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(-1,+1)));
            }
            if (gameboard.checkRegularMovePotential(piece.returnModified(-1,-1)))
            {
                gameboard(piece).possibleMoves.emplace_back(Move(piece.returnModified(-1,-1)));
            }
            break;
        default:
            break;
    }
}



void Game::initializePossibleMovesForPlayersPieces(Player& player)
{
    for (int i = 0; i < 8 ; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gameboard(i, j).type == player.color.first || gameboard(i, j).type == player.color.second)
            {
                findAllMoves({i, j});
            }
        }
    }
}



Position Game::executeSelectedMove(Move chosenMove, Position chosenPiece, Player& player, sf::RenderWindow& w)
{
    Position landingPosition;
    // jesli to bicie
    if (chosenMove.type == Move::JUMP)
    {
        gameboard(chosenMove.landingPosition).type = gameboard(chosenPiece).type;
        gameboard(chosenPiece).type = Field::FREE;
        gameboard(chosenMove.jumpedPiece).type = Field::FREE;
        Position landingPosition(chosenMove.landingPosition);
        if (player.color.first == Field::RED || player.color.first == Field::REDKING)
        {
            redJumps++;
        }
        else
        {
            whiteJumps++;
        }
        findJumps(landingPosition);
        while (!gameboard(landingPosition).possibleMoves.empty())
        {
            std::cout << "(i) Sa dodatkowe bicia";
            chosenMove = player.selectMove(gameboard, landingPosition, w);
            gameboard(chosenMove.landingPosition).type = gameboard(landingPosition).type;
            gameboard(landingPosition).type = Field::FREE;
            gameboard(chosenMove.jumpedPiece).type = Field::FREE;
            landingPosition = Position(chosenMove.landingPosition);
            if (player.color.first == Field::RED || player.color.first == Field::REDKING)
            {
                redJumps++;
            }
            else
            {
                whiteJumps++;
            }
            findJumps(landingPosition);
        }
    }
    // jesli zwykly ruch
    else
    {
        gameboard(chosenMove.landingPosition).type = gameboard(chosenPiece).type;
        gameboard(chosenPiece).type = Field::FREE;
        landingPosition = chosenMove.landingPosition;
    }
    return landingPosition;
}



void Game::turnIntoKings()
{
    for (int i = 0; i < 8 ; i++)
    {
        if (gameboard(7,i).type == Field::RED)
        {
            gameboard(7,i).type = Field::REDKING; 
        }
    } 
    for (int i = 0; i < 8 ; i++)
    {
        if (gameboard(0,i).type == Field::WHITE)
        {
            gameboard(0,i).type = Field::WHITEKING; 
        }
    } 
}



void Game::turn(Player& player)
{
    sf::RenderWindow dummy;
    initializePossibleMovesForPlayersPieces(player);
    Position chosenPiece = player.selectPiece(gameboard);
    Move chosenMove = player.selectMove(gameboard, chosenPiece);
    executeSelectedMove(chosenMove, chosenPiece, player, dummy);
    turnIntoKings();
}



void Game::turn(Player& player, sf::RenderWindow& w)
{
    initializePossibleMovesForPlayersPieces(player);
    Position chosenPiece = player.selectPiece(gameboard, w);
    Move chosenMove = player.selectMove(gameboard, chosenPiece, w);
    executeSelectedMove(chosenMove, chosenPiece, player, w);
    /*
    while (chosenMove.type == Move::JUMP)
    {
        Position landingPosiiton = executeSelectedMove(chosenMove, chosenPiece, player, w);
        Move chosenMove = player.selectMove(gameboard, landingPosiiton, w);   
    }
    */
    turnIntoKings();
}



void Game::draw()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            switch (gameboard(i, j).type)
            {
            case Field::INVALID:
                std::cout << "#";
                break;
            case Field::FREE:
                std::cout << " ";
                break;
            case Field::RED:
                std::cout << "r";
                break;
            case Field::WHITE:
                std::cout << "w";
                break;    
            case Field::REDKING:
                std::cout << "R";
                break;
            case Field::WHITEKING:
                std::cout << "W";
                break;
            }
        }
        std::cout << "\n";
    }
}