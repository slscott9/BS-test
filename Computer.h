#ifndef COMPUTER_H
#define COMPUTER_H
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "GameBoard.h"
#include "Ships.h"

class Computer : public Player
{
    private:
        bool GameStarted;
        int Xinput;
        int Yinput;
        bool isVertical;
        bool locatedHit;
        bool shipInArea;
    //variables to tell if the direction we go in is not a hit
        bool xLeft,xRight, yUp, yDown;

    //variables to hold the original x and y hit
        int XhitCoor;
        int YhitCoor;

    //aggregate class instances
        GameBoard Board;
        Ship Ships[MAXNUMSHIPS]; //contains each ship

    //arrays to hold ship information
        char ShipAbrev[MAXNUMSHIPS] ={'P','S','D','B','C'};
        std::string ShipNames[MAXNUMSHIPS] = {"Patrol Boat","Submarine","Destroyer","Battleship","Carrier"};
        int ShipSizes[MAXNUMSHIPS] = {2,3,3,4,5};
        

    public:
    //constructors
        Computer();

    //Native functions for Computer class
        int getZeroNine();//generates random 0 - 9 for x and y coor


        bool setVertical();//generates 1 for vertical or 0 for hoizontal sets isVertical var

        bool getIsVertical();

    //redefined virtual functions
        void setXY();

        void setShips();

        int getX();

        int getY();

        bool boardIsShipsHit(int, int, int); //redefined virtual function
        bool boardIsShipsHit(int, int); //virtual overloaded from player


        void displayBoard();

        bool isWinner();
    
    //smart functions to determine a shot area
        bool setLocatedHit(bool);
        bool setShipInArea();
        bool getLocatedHit();
        bool getShipInArea();

        void smartChoice();//smart function that tests each direction


        //functions to set x and y hit coordinates
            void setXhitCoor(int);
            void setYhitCoor(int);

            int getXhitCoor();
            int getYhitCoor();

        //function to set xLeft xRight yup, ydown
            void setXleft(bool);
            void setXright(bool);
            void setYup(bool);
            void setYdown(bool);

};

#endif 





