#include "../inc/board.hpp"



std::ostream& operator << (std::ostream& out, Position p)
{
    out << p.row << " " << p.column;
    return out;
}



std::ostream& operator << (std::ostream& out, Move m)
{
    out << "source: " << m.source << "  landing: " << m.landing;
    if (m.type == Move::JUMP) out << "  jumped: " << m.jumpedPiece;
    return out;
}



Board::Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i+j)%2 == 0)
            {
                board[i][j]= FieldType::INVALID;
            }
            else
            {
                if (i < 3)
                {
                    board[i][j] = FieldType::RED;
                }
                else if (i > 4)
                {
                    board[i][j] = FieldType::WHITE;
                }
                else
                {
                    board[i][j] = FieldType::FREE;
                }
            }
        }
    }
}



bool Board::canMove(Position source, Position landing)
{
    
    if (landing.row < 0 || landing.row > 7 || landing.column < 0 || landing.column > 7)
    {
        return false;
    }
    if (board[landing.row][landing.column] != FieldType::FREE)
    {
        return false;
    }
    return true;
}



bool Board::canJump(Position source, Position jumped, Position landing)
{
    std::pair<FieldType, FieldType> enemy;
    if (at(source) == FieldType::WHITE || at(source) == FieldType::WHITEKING)
    {
        enemy = {FieldType::RED, FieldType::REDKING};
    }
    else
    {
        enemy = {FieldType::WHITE, FieldType::WHITEKING};
    }
    if (jumped.row < 0 || jumped.row > 7 || jumped.column < 0 || jumped.column > 7)
    {
        return false;
    }
    if (landing.row < 0 || landing.row > 7 || landing.column < 0 || landing.column > 7)
    {
        return false;
    }
    if (at(jumped) != enemy.first && at(jumped) != enemy.second)
    {
        return false;
    }
    if (at(landing) != FieldType::FREE)
    {
        return false;
    }
    return true;
}



std::vector<Move> Board::getPossibleMoves(Position piece)
{
    std::vector<Move> moves;
    switch (at(piece))
    {
        case FieldType::WHITE:
            if (canJump(piece, piece.changed(-1, -1), piece.changed(-2, -2))) moves.emplace_back(Move(piece, piece.changed(-1, -1), piece.changed(-2, -2)));
            if (canJump(piece, piece.changed(-1, +1), piece.changed(-2, +2))) moves.emplace_back(Move(piece, piece.changed(-1, +1), piece.changed(-2, +2)));
            if (canMove(piece, piece.changed(-1, -1))) moves.emplace_back(Move(piece, piece.changed(-1, -1)));
            if (canMove(piece, piece.changed(-1, +1))) moves.emplace_back(Move(piece, piece.changed(-1, +1)));
            break;

        case FieldType::RED:
            if (canJump(piece, piece.changed(+1, -1), piece.changed(+2, -2))) moves.emplace_back(Move(piece, piece.changed(+1, -1), piece.changed(+2, -2)));
            if (canJump(piece, piece.changed(+1, +1), piece.changed(+2, +2))) moves.emplace_back(Move(piece, piece.changed(+1, +1), piece.changed(+2, +2)));
            if (canMove(piece, piece.changed(+1, -1))) moves.emplace_back(Move(piece, piece.changed(+1, -1)));
            if (canMove(piece, piece.changed(+1, +1))) moves.emplace_back(Move(piece, piece.changed(+1, +1)));
            break;

        case FieldType::REDKING: case FieldType::WHITEKING:
            if (canJump(piece, piece.changed(-1, -1), piece.changed(-2, -2))) moves.emplace_back(Move(piece, piece.changed(-1, -1), piece.changed(-2, -2)));
            if (canJump(piece, piece.changed(-1, +1), piece.changed(-2, +2))) moves.emplace_back(Move(piece, piece.changed(-1, +1), piece.changed(-2, +2)));
            if (canJump(piece, piece.changed(+1, -1), piece.changed(+2, -2))) moves.emplace_back(Move(piece, piece.changed(+1, -1), piece.changed(+2, -2)));
            if (canJump(piece, piece.changed(+1, +1), piece.changed(+2, +2))) moves.emplace_back(Move(piece, piece.changed(+1, +1), piece.changed(+2, +2)));
            if (canMove(piece, piece.changed(-1, -1))) moves.emplace_back(Move(piece, piece.changed(-1, -1)));
            if (canMove(piece, piece.changed(-1, +1))) moves.emplace_back(Move(piece, piece.changed(-1, +1)));
            if (canMove(piece, piece.changed(+1, -1))) moves.emplace_back(Move(piece, piece.changed(+1, -1)));
            if (canMove(piece, piece.changed(+1, +1))) moves.emplace_back(Move(piece, piece.changed(+1, +1)));
            break;
        case FieldType::FREE: case FieldType::INVALID:
            break;

    }
    return moves;
}



void Board::removeField(Position p)
{
    board[p.row][p.column] = FieldType::FREE;
}



void Board::swapFields(Position p1, Position p2) 
{
    FieldType tmp = board[p1.row][p1.column];
    board[p1.row][p1.column] = board[p2.row][p2.column];
    board[p2.row][p2.column] = tmp;
}



void Board::executeMove(Move chosenMove)
{
    if (chosenMove.type == Move::REGULAR)
    {
        swapFields(chosenMove.source, chosenMove.landing);
    }
    if (chosenMove.type == Move::JUMP)
    {
        swapFields(chosenMove.source, chosenMove.landing);
        removeField(chosenMove.jumpedPiece);
    }
}



void Board::kingify()
{
    for (int i = 0; i < 8; i++)
    {
        if (board[0][i] == Board::FieldType::WHITE) board[0][i] = Board::FieldType::WHITEKING;
    }
    for (int i = 0; i < 8; i++)
    {
        if (board[7][i] == Board::FieldType::RED) board[7][i] = Board::FieldType::REDKING;
    }
}