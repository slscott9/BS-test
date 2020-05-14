#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iomanip>
#include "Ships.h"
#define ROWS 10
#define COLS 10
#define TENSIZE 10
#define WIDTH 8


class GameBoard
{
    private:
        char Board[ROWS][COLS]; //actual game board
        char headerArray[COLS] {'A','B','C','D','E','F','G','H','I','J'}; //Displays x coordinates
        int sideArray[ROWS] = {0,1,2,3,4,5,6,7,8,9}; //Displays y coordinates
        

    public:
    //constructor
        GameBoard();
    

        bool isXYfilled(int xpos, int ypos);


    //This function displays the game board
        void showBoard();
        

        void fillBoard(int, int, char);






    

       
};

#endif
