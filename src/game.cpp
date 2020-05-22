#include <iostream>

#include "../inc/game.hpp"



void Game::getPossibleMoves(Position piece)
{
    switch(gameboard(piece.row,piece.column).type)
    {
        case Field::RED:
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2), Field::RED))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Jump(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2), Field::RED))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Jump(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2)));
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
        case Field::WHITE:
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2), Field::WHITE))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Jump(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column-1), Position(piece.row+2, piece.column-2), Field::WHITE))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Jump(Position(piece.row+1, piece.column-1), Position(piece.row+2, piece.column-2)));
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
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2), Field::RED))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Jump(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row-1, piece.column-1), Position(piece.row-2, piece.column-2), Field::RED))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Jump(Position(piece.row-1, piece.column+1), Position(piece.row-2, piece.column+2)));
            }
            break;
        case Field::WHITE:
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2), Field::WHITE))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Jump(Position(piece.row+1, piece.column+1), Position(piece.row+2, piece.column+2)));
            }
            if (gameboard.checkJumpPotential(Position(piece.row+1, piece.column-1), Position(piece.row+2, piece.column-2), Field::WHITE))
            {
                gameboard(piece.row, piece.column).possibleMoves.push_back(Jump(Position(piece.row+1, piece.column-1), Position(piece.row+2, piece.column-2)));
            }
            break;
        case Field::REDKING: case Field::WHITEKING:
            // ??? 
            break;
        default:
            break;
    }
}



void Game::removeJumpedPieces(std::vector<Position> jumpedPiecesInCurrentTurn)
{
    
}



void Game::turn()
{
    std::pair<Field::Type, Field::Type> currentTurnPlayer = {Field::WHITE, Field::WHITEKING};
    int row, column;
    do
    {
        std::cin >> row >> column;
    } while (gameboard(row, column).type != currentTurnPlayer.first || gameboard(row, column).type != currentTurnPlayer.first || row < 0 || row > 7 || column < 0 || column > 7);
    Position chosenPiece(row, column);
    getPossibleMoves(chosenPiece);
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



    // jesli zwykly ruch
    gameboard(chosenMove.landingPosition.row, chosenMove.landingPosition.column).type = gameboard(chosenPiece.row, chosenPiece.column).type;
    gameboard(chosenPiece.row, chosenPiece.column).type = Field::FREE;
    


    
    //nastepuje wybranie pionka

}


