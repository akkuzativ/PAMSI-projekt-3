#ifndef BOARD_HH
#define BOARD_HH

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

class Jump
{
    private:
        std::vector<Position> jumpedPieces;
    public:
};

class Move
{
    private:
        std::vector<Jump> executedJumps;
        Position finalDestination;
    public:
};


class Field
{
    public:
        enum Type {INVALID, FREE, RED, WHITE, REDKING, WHITEKING};
        friend class Board;
    private:
        Type type;
        Position positionOnBoard;
        std::vector<Move> possibleMoves;
        std::pair<Type, Type> getEnemy();
        static std::pair<Type, Type> getEnemy(Type type);

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
        bool checkRegularMovePotential(Position position);
        bool checkJumpPotential(Position pieceToJumped, Position landingPosition, Field::Type currentTurn);
};






#endif