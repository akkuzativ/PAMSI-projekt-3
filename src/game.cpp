#include <iostream>


#include "../inc/game.hpp"



void Game::getPossibleMoves(Position piece)
{
    gameboard(piece.row, piece.column).possibleMoves.clear();
    switch(gameboard(piece.row,piece.column).type)
    {
        case Field::RED:
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2), Field::RED))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column-1), Position(piece.row+2, piece.column-2), Field::RED))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            if (gameboard.checkRegularMovePotential(Position(piece.row+1, piece.column-1)))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column-1)));
            }
            if (gameboard.checkRegularMovePotential(Position(piece.row+1, piece.column+1)))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1)));
            }
            break;
        case Field::WHITE:
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2), Field::WHITE))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2), Field::WHITE))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2)));
            }
            if (gameboard.checkRegularMovePotential(Position(piece.row-1, piece.column-1)))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column-1)));
            }
            if (gameboard.checkRegularMovePotential(Position(piece.row-1, piece.column+1)))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column+1)));
            }
            break;
        case Field::REDKING: case Field::WHITEKING:
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2), gameboard(piece.row,piece.column).type))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column-1), Position(piece.row+2, piece.column-2), gameboard(piece.row,piece.column).type))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2), gameboard(piece.row,piece.column).type))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2), gameboard(piece.row,piece.column).type))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2)));
            }
            if (gameboard.checkRegularMovePotential(Position(piece.row+1, piece.column-1)))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column-1)));
            }
            if (gameboard.checkRegularMovePotential(Position(piece.row+1, piece.column+1)))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1)));
            }
            if (gameboard.checkRegularMovePotential(Position(piece.row-1, piece.column-1)))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column-1)));
            }
            if (gameboard.checkRegularMovePotential(Position(piece.row-1, piece.column+1)))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column+1)));
            }
            break;
        default:
            break;
    }
}


void Game::lookForAdditionalJumps(Position piece)
{
    gameboard(piece.row, piece.column).possibleMoves.clear();
    switch(gameboard(piece.row,piece.column).type)
    {
        case Field::RED:
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2), Field::RED))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column-1), Position(piece.row+2, piece.column-2), Field::RED))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            break;
        case Field::WHITE:
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2), Field::WHITE))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2), Field::WHITE))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2)));
            }
            break;
        case Field::REDKING:case Field::WHITEKING:
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2), gameboard(piece.row,piece.column).type))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column-1), Position(piece.row+2, piece.column-2), gameboard(piece.row,piece.column).type))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2), gameboard(piece.row,piece.column).type))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2), gameboard(piece.row,piece.column).type))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Move(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2)));
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
                getPossibleMoves({i, j});
            }
        }
    }
}

void Game::executeSelectedMove(Move chosenMove, Position chosenPiece, Player& player)
{
    // jesli to bicie
    if (chosenMove.jumpedPiece != Position(-99, -99))
    {
        gameboard(chosenMove.landingPosition.row, chosenMove.landingPosition.column).type = gameboard(chosenPiece.row, chosenPiece.column).type;
        gameboard(chosenMove.jumpedPiece.row, chosenMove.jumpedPiece.column).type = Field::FREE;
        Position positionAfterJump(chosenMove.landingPosition.row, chosenMove.landingPosition.column);
        switch (player.color.first)
            {
                case Field::RED: case Field::REDKING:
                    redJumps++;
                    break;
                case Field::WHITE: case Field::WHITEKING:
                    whiteJumps++;
                    break;
                default:
                    break;
            }
        lookForAdditionalJumps(positionAfterJump);
        while (!gameboard(positionAfterJump.row, positionAfterJump.column).possibleMoves.empty())
        {
            std::cout << "wybierz ruch: ";
            for (u_int i = 0; i < gameboard(positionAfterJump.row, positionAfterJump.column).possibleMoves.size(); i++)
            {
                std::cout << gameboard(positionAfterJump.row, positionAfterJump.column).possibleMoves[i].landingPosition.row << " " << gameboard(positionAfterJump.row, positionAfterJump.column).possibleMoves[i].landingPosition.column << "\n";
            }
            u_int moveNumber;
            do
            {
                std::cin >> moveNumber;
            } while ( (!gameboard(positionAfterJump.row, positionAfterJump.column).possibleMoves.empty() && moveNumber > gameboard(positionAfterJump.row, positionAfterJump.column).possibleMoves.size() ) || moveNumber < 0);
            chosenMove = gameboard(positionAfterJump.row, positionAfterJump.column).possibleMoves[moveNumber];
            gameboard(chosenMove.landingPosition.row, chosenMove.landingPosition.column).type = gameboard(positionAfterJump.row, positionAfterJump.column).type;
            gameboard(chosenMove.jumpedPiece.row, chosenMove.jumpedPiece.column).type = Field::FREE;
            gameboard(positionAfterJump.row, positionAfterJump.column).type = Field::FREE;
            positionAfterJump = Position(chosenMove.landingPosition.row, chosenMove.landingPosition.column);
            switch (player.color.first)
            {
                case Field::RED: case Field::REDKING:
                    redJumps++;
                    break;
                case Field::WHITE: case Field::WHITEKING:
                    whiteJumps++;
                    break;
                default:
                    break;
            }     
        }
    }
    // jesli zwykly ruch
    gameboard(chosenMove.landingPosition.row, chosenMove.landingPosition.column).type = gameboard(chosenPiece.row, chosenPiece.column).type;
    gameboard(chosenPiece.row, chosenPiece.column).type = Field::FREE;
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
    initializePossibleMovesForPlayersPieces(player);
    Position chosenPiece = player.selectPiece(gameboard);
    Move chosenMove = player.selectMove(gameboard, chosenPiece);
    executeSelectedMove(chosenMove, chosenPiece, player);
    turnIntoKings();
}

void Game::turn(Player& player, sf::RenderWindow& w)
{
    initializePossibleMovesForPlayersPieces(player);
    Position chosenPiece = player.selectPiece(gameboard, w);
    Move chosenMove = player.selectMove(gameboard, chosenPiece, w);
    executeSelectedMove(chosenMove, chosenPiece, player);
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
