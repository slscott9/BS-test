#include "GameBoard.h"
#include <iostream>
#include <iomanip>
using namespace std;

//constructor fills the gameboard with astericks
GameBoard::GameBoard()
{   
    
}

void GameBoard::showBoard()
{   
    cout << '\t'; //tabs header number over

    for (int x = 0; x < TENSIZE; x++)
    {
        cout << setw(WIDTH) << headerArray[x]; //prints header numbers 0 - 9
    }
    
    cout << endl << endl;

//prints side numbers then game board
    for (int row = 0; row < ROWS; row++)
    {   
        cout << setw(WIDTH) << sideArray[row]; 

        for (int col = 0; col < COLS; col++)
        {
            cout << setw(WIDTH) << Board[row][col];
        }
        cout << endl << endl;
    }
}

bool GameBoard::isXYfilled(int x, int y)
{
    if(Board[y][x] != ' ')
    {
        return true;
    }
}

void GameBoard::fillBoard(int xCoor, int yCoor, char fillChar)
{
    Board[yCoor][xCoor] = fillChar;
}






