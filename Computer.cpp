#include "Computer.h"
#include <iostream>
using namespace std;


//constructor
Computer::Computer()
{   
    srand((unsigned) time(0));

   for (int x = 0; x < MAXNUMSHIPS; x++) //sets each ship instance variables 
    {
        Ships[x].setAll(ShipNames[x], ShipAbrev[x], ShipSizes[x]);
    }
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            Board.fillBoard(col, row, ' ');
            MarkedBoard.fillBoard(col, row, ' ');
        }
    }
        shipInArea = false;
        GameStarted = false;
        Xinput = 0;
        Yinput = 0;
        isVertical = false;
        shipInArea = false;
        hitCount = 0;
        missCount = 0;


    //variables to hold the original x and y hit
        int XhitCoor = 0;
        int YhitCoor = 0;
}

//functions native to computer class
int Computer::getZeroNine()
{   
    int randomNumber = (rand() % 10) + 0;

    return randomNumber;
}

bool Computer::getIsVertical()
{
    return isVertical;
}

bool Computer::setVertical()
{
    int rand0or1 =  rand() % 2;

    if(rand0or1 == 1)
    {
        isVertical = true;
    }
    else
    {
        isVertical = false;
    }
    
}

//redefined virtual functions from Player base class
void Computer::setXY()
{   
    if(shipInArea)
    {   
        cout << "in SHIPINAREA if" << endl;
        smartChoice();
    }
    else
    {

        Xinput = getZeroNine();
        Yinput = getZeroNine();    
    }
}


void Computer::smartChoice()
{   
    enum xDir {RIGHT = 1, XNOCHANGE = 0, LEFT = -1};
    enum yDir {DOWN = 1, YNOCHANGE = 0, UP = -1};

    int x = getXhitCoor();
    int y = getYhitCoor();

    if (getHitCount() == 1)
    {   
        cout << "in misscount = 1" << endl;
        Xinput = x+=1;
        Yinput = y;
    }
    else if(getHitCount() == 2)
    {   
                cout << "in misscount = 2" << endl;

        Xinput = x-=1;
        Yinput = y;
    }
    else if(getHitCount() == 3)
    {   
                cout << "in misscount = 3" << endl;

        Xinput = x;
        Yinput = y+=1;
    }
    else if(getHitCount() == 4)
    {   
                cout << "in misscount = 4" << endl; //going in this else because miss count is 
                                //is zero at the start

        Xinput = x;
        Yinput = y-=1;
    }
    
    

}

void Computer::setMissCount(int misses)
{
    missCount = misses;
}

int Computer::getMissCount()
{
    return missCount;
}


void Computer::setXhitCoor(int xCoor)
{
    XhitCoor = xCoor;
}

void Computer::setYhitCoor(int yCoor)
{
    YhitCoor = yCoor;
}

int Computer::getXhitCoor()
{
    return XhitCoor;
}

int Computer::getYhitCoor()
{
    return YhitCoor;
}

void Computer::setHitCount(int tempHitCount)
{
   
    hitCount+= tempHitCount;

}

int Computer::getHitCount()
{
    return hitCount;
}


bool Computer::setShipInArea()
{
      shipInArea = true;
}


bool Computer::getShipInArea()
{   
    return shipInArea;
}




int Computer::getX()
{
    return Xinput;
}

int Computer::getY()
{
    return Yinput;
}



bool Computer::boardIsShipsHit(int xCoor, int yCoor, int numShipSetup)
{   
    for(int ship = 0; ship < numShipSetup; ship++)
    {
        if(Ships[ship].isHit(xCoor, yCoor, GameStarted))
        {
            return true;
        }
    }
    return false;
}

bool Computer::boardIsShipsHit(int xCoor, int yCoor)//redefined virtual and overloaded
{   
    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {
        if(Ships[ship].isHit(xCoor, yCoor, GameStarted))
        {   
    
            //MarkedBoard.fillBoard(xCoor, yCoor, 'H');
            return true;
        }
    }
    return false;
}

void Computer::displayBoard()
{   
    cout << "GAMEBOARD" << endl;
    Board.showBoard();
    cout << endl << "MARKED BOARD " << endl;
    MarkedBoard.showBoard();
}

void Computer::setShips()
{   
    //enum class will tell the  direction we should go
    //based on isVertical.
    enum xDir {RIGHT = 1, XNOCHANGE = 0, LEFT = -1};
    enum yDir {DOWN = 1, YNOCHANGE = 0, UP = -1};

    xDir Xdirection = RIGHT; //defaults
    yDir Ydirection = DOWN;

    int shipsSetup = 0;

    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        bool good = true;
        do
        {   
            good = true;

            setXY(); //sets X, Y, and Vertical
            setVertical();

            if(getIsVertical())
            {   
                 Xdirection = XNOCHANGE;
                if((getY() + Ships[ship].getShipSize()-1) > 9)
                {   
                     Ydirection = UP;
                }
                else
                {
                    Ydirection = DOWN;
                }
            }
            else
            {   
                 Ydirection = YNOCHANGE;

                if((getX() + Ships[ship].getShipSize()-1) > 9)
                {   
                     Xdirection = LEFT;
                }
                else
                {
                    Xdirection = RIGHT;
                }
                
            }//end if vertical

            int x = getX();
            int y = getY();

            for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
            {   
                if(boardIsShipsHit(x,y,shipsSetup))//THIS IS WHERE YOU STOPPEDDD
                {
                    good = false;
                    break;
                }
                else
                {   
                     y+=Ydirection;
                     x+=Xdirection;
                }
                
            }//end nested for
            
            if(good)
            {   
                x = getX();
                y = getY();
                for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
                {
                    Ships[ship].setCoor(x,y,coor);
                    Board.fillBoard(x,y, Ships[ship].getShipAbrev());
                   
                    y+=Ydirection;
                    x+=Xdirection;
                }
            }

        } while (!good);

        shipsSetup++;
    
    }//end ship for loop

    GameStarted = true; //When this function is done the ships will be set
                        //and game is ready to start
}



bool Computer::isWinner()
{   
    cout << "Computer's hits " << endl;
    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        int total = 0;
        for(int ship = 0; ship < MAXNUMSHIPS; ship++)
        {   
            if(Ships[ship].getIsSunk())
            {
                total++;
            }
        }
        if(total == 5)
        {   
            cout << "YOU WON!!" << endl;
            return true;
        }
        return false;

    }//end for loop
}


void Computer::FillASpot(int x, int y, char shot)
{   
    if(shot == 'H')
    {
        MarkedBoard.fillBoard(x, y, 'H');

    }
    else
    {
        MarkedBoard.fillBoard(x, y, 'O');
    }
    
}

void Computer::showShipCoor()
{
    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        cout << Ships[ship].getShipName() << endl;
        for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
        {
            cout << "X coor " << Ships[ship].getShipXCoor(coor) << endl;
            cout << "Ycoor " << Ships[ship].getShipYCoor(coor) << endl;
        }
        cout << endl;
    }
}