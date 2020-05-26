#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>





struct Position
{
    int row;
    int column;
    Position() {};
    Position(int r, int c) {row = r; column = c;};
    bool operator==(Position p) {if (row == p.row && column == p.column) return true; else return false; };
    bool operator!=(Position p) {if (column != p.column && column != p.column) return true; else return false; };
    Position changed(int drow, int dcolumn) {return Position(row+drow, column+dcolumn);};
};



struct Move
{
    enum MoveType {REGULAR, JUMP};
    MoveType type;
    Position source;
    Position landing;
    Position jumpedPiece;
    Move() {};
    Move (Position s, Position l) {source = s; landing = l; type = REGULAR;};
    Move (Position s, Position j, Position l) {source = s; jumpedPiece = j; landing = l; type = JUMP;};
};




class Board
{
    public:
        enum class FieldType {INVALID, FREE, RED, WHITE, REDKING, WHITEKING};
    private:
        FieldType board[8][8];
    public:
        Board();
        void removeField(Position p)
        {
            board[p.row][p.column] = FieldType::FREE;
        };
        void swapFields(Position p1, Position p2) 
        {
            FieldType tmp = board[p1.row][p1.column];
            board[p1.row][p1.column] = board[p2.row][p2.column];
            board[p2.row][p2.column] = tmp;
        };
        bool canMove(Position source, Position landing);
        bool canJump(Position source, Position jumped, Position landing);
        std::vector<Move> getPossibleMoves(Position piece);
        FieldType at(Position p) {return board[p.row][p.column];};
        FieldType& operator()(int r, int c) {return board[r][c];};
        FieldType& operator()(Position p) {return board[p.row][p.column];};
};



#endif