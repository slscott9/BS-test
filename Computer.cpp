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
        }
    }
    xLeft = false;
    xRight = false;
    yUp = false;
    yDown = false;

    GameStarted = false;
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
        smartChoice();
    }
    Xinput = getZeroNine();
    Yinput = getZeroNine();
}


void Computer::smartChoice()
{
    
    int loopCount = 0;
    int hitCount = 0;
    if (!locatedHit)//if true we have not going in the right direction
    {   
            if(loopCount == 1)
            {
                xRight = false;
            }
            else if(loopCount == 2)
            {
                xLeft = false;
            }
            else if(loopCount == 3)
            {
                yDown = false;
            }
            else if(loopCount == 4)
            {
                yUp = false;
            }
            
        if(xRight && xLeft && yUp && yDown)
        {
            Xinput = XhitCoor++; //x goes right
            Yinput = YhitCoor;
            loopCount++;
        }
        else if(!xRight)
        {
            Xinput = XhitCoor--;// x goes left
            Yinput = YhitCoor;

            loopCount++;
        }
        else if(!xRight && !xLeft)
        {
            Xinput = XhitCoor;
            Yinput = YhitCoor++; // y goes down
            loopCount++;
        }
        else if(!xRight && !xLeft && !yDown)
        {
            Xinput = XhitCoor;
            Yinput = YhitCoor--; // y goes up
            loopCount++;

        }
    }

    else if (locatedHit) //if true we are going in the right direction
    {   
        if(loopCount == 1)
        {
            Xinput = XhitCoor++; //x goes right
            Yinput = YhitCoor;
        }
        else if(loopCount == 2)
        {
            Xinput = XhitCoor--; //x goes left
            Yinput = YhitCoor;
        }
        else if(loopCount == 3)
        {
            Xinput = XhitCoor;// y goes up
            Yinput = YhitCoor--;
        }
        else if(loopCount == 4)
        {
            Xinput = XhitCoor;
            Yinput = YhitCoor++; // y goes down
        }
    } //end else if locatedHit

}//end function smartchoice





void Computer::setXleft(bool left) //see if we should go left
{
    if(left)
    {
        xLeft = true;
    }
    xLeft = false;
}

void Computer::setXright(bool hit)
{
    if(hit)
    {
        xRight = true;
    }
    xRight = false;
}

void Computer::setYup(bool hit)
{
    if(hit)
    {
        yUp = true;
    }
    yUp = false;
}

void Computer::setYdown(bool hit)
{
    if(hit)
    {
        yDown = true;
    }
    yDown = false;
}

void Computer::setXhitCoor(int xCoor)
{
    XhitCoor = xCoor;
}

void Computer::setYhitCoor(int yCoor)
{
    YhitCoor = yCoor;
}


bool Computer::setLocatedHit(bool hit)
{
    if(hit)
    {
        locatedHit = true;
    }
    locatedHit = false;
}

bool Computer::setShipInArea()
{
   
    shipInArea = true;
}


bool Computer::getShipInArea()
{
    return shipInArea;
}

bool Computer::getLocatedHit()
{
    return locatedHit;
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
            Board.fillBoard(xCoor, yCoor, 'H');
            return true;
        }
    }
    return false;
}





void Computer::displayBoard()
{
    Board.showBoard();
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

    }
}


