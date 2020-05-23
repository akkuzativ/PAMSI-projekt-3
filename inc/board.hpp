#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>


class Position
{
    private:
    public:
        int row;
        int column;


        Position() {};
        Position(int r, int c) {row = r; column = c;};
        ~Position() {};
        bool operator ==(Position p) {if (row == p.row && column == p.column) return true; else return false;};
        bool operator !=(Position p) {if (row != p.row || column != p.column) return true; else return false;};
        
};


class Move
{
    protected:
        Position jumpedPiece;
        Position landingPosition;


    public:
        Move() {};
        Move(Position lP) {jumpedPiece = {-99, -99}; landingPosition = lP;};
        Move(Position jP, Position lP) {jumpedPiece = jP; landingPosition = lP;};

        friend class Player;
        friend class Field;
        friend class HumanPlayer;
        friend class AIPlayer;
        friend class Game;
};





class Field
{
    public:
        enum Type {INVALID, FREE, RED, WHITE, REDKING, WHITEKING};
        static std::pair<Type, Type> getEnemy(Type type);
        friend class Board;
        friend class Game;
        friend class Player;
        friend class HumanPlayer;
        friend class AIPlayer;
        friend class Renderer;


    private:
        Type type;
        Position positionOnBoard;
        std::vector<Move> possibleMoves;
    public:
};

class Board
{
    private:
        Field _board[8][8];
        std::vector<Field*> redPieces;
        std::vector<Field*> whitePieces;


    public:
        Board();
        ~Board() {};
        std::vector<Field*> getRedPieces();
        std::vector<Field*> getWhitePieces();
        Field& operator()(int i, int j) {return _board[i][j];};
        bool checkRegularMovePotential(Position position);
        bool checkJumpPotential(Position pieceToJumped, Position landingPosition, Field::Type currentTurn);

        
};






#endif