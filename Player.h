#ifndef PLAYER_H
#define PLAYER_H
class Player
{   
    public:
        virtual void setXY() = 0;
        virtual void setShips() = 0;
        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual bool boardIsShipsHit(int, int, int) = 0;
        virtual bool boardIsShipsHit(int, int) = 0;

        virtual void displayBoard() = 0;
        virtual bool isWinner() = 0;

};

#endif