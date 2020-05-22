#include <iostream>

#include "../inc/game.hpp"



void Game::getPossibleMoves(Position piece)
{
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
            // ??? 
            break;
        default:
            break;
    }
}


void Game::lookForAdditionalJumps(Position piece)
{
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
        case Field::REDKING: case Field::WHITEKING:
            // ??? 
            break;
        default:
            break;
    }
}



void Game::turn()
{
    for (int i = 0; i < 8 ; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gameboard(i, j).type == currentTurnPlayer.first || gameboard(i, j).type == currentTurnPlayer.second)
            {
                getPossibleMoves({i, j});
            }
        }
    }
    int row, column;
    do
    {
        std::cout << "wybierz pionek: ";
        std::cin >> row >> column;
    } while (gameboard(row, column).type != currentTurnPlayer.first || gameboard(row, column).type != currentTurnPlayer.first || row < 0 || row > 7 || column < 0 || column > 7 || gameboard(row, column).possibleMoves.empty());
    Position chosenPiece(row, column);
    std::cout << "wybierz ruch: ";
    for (u_int i = 0; i < gameboard(chosenPiece.row, chosenPiece.column).possibleMoves.size(); i++)
    {
        std::cout << gameboard(chosenPiece.row, chosenPiece.column).possibleMoves[i].landingPosition.row << " " << gameboard(chosenPiece.row, chosenPiece.column).possibleMoves[i].landingPosition.column << "\n";
    }
    u_int moveNumber;
    do
    {
        std::cin >> moveNumber;
    } while (moveNumber > gameboard(chosenPiece.row, chosenPiece.column).possibleMoves.size() || moveNumber < 0);

    Move chosenMove = gameboard(chosenPiece.row, chosenPiece.column).possibleMoves[moveNumber];

    // jesli to bicie

    if (chosenMove.jumpedPiece != Position(-99, -99))
    {
        gameboard(chosenMove.landingPosition.row, chosenMove.landingPosition.column).type = gameboard(chosenPiece.row, chosenPiece.column).type;
        gameboard(chosenMove.jumpedPiece.row, chosenMove.jumpedPiece.column).type = Field::FREE;
    }


    // jesli zwykly ruch
    gameboard(chosenMove.landingPosition.row, chosenMove.landingPosition.column).type = gameboard(chosenPiece.row, chosenPiece.column).type;
    gameboard(chosenPiece.row, chosenPiece.column).type = Field::FREE;
    


    
    //nastepuje wybranie pionka
    currentTurnPlayer = Field::getEnemy(currentTurnPlayer.first);
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
                std::cout << "R";
                break;
            }
        }
        std::cout << "\n";
    }
}

