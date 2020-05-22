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
        
};


class Move
{
    protected:
        Position landingPosition;

        friend class Game;
    public:
        Move() {};
        Move(Position lP) {landingPosition = lP;};
};


class Jump: public Move
{
    private:
        Position jumpedPiece;
    public:
        Jump() {};
        Jump(Position jP, Position lP) {jumpedPiece = jP; landingPosition = lP;};
};



class Field
{
    public:
        enum Type {INVALID, FREE, RED, WHITE, REDKING, WHITEKING};
        static std::pair<Type, Type> getEnemy(Type type);
        friend class Board;
        friend class Game;


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