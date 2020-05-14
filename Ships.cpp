#include "Ships.h"
#include <string>
#include <iostream>
using namespace std;

Ship::Ship() //default constructor
{
    ShipName = "";
    ShipSize = 0;
    IsSunk = false;
    HitCount = 0;
}

Ship::Ship(std::string name, char abrev, int size) //constructor receives parameters from gameboard class
{   
   setAll(name, abrev, size); //sets a ship instances private vars - shipName, shipAbrev, shipSize
}

//setters

void Ship::setCoor(int xCoor, int yCoor, int index)
{
    shipXCoor[index] = xCoor;
    shipYCoor[index] = yCoor;
}


void Ship::setAll(std::string name, char abrev, int size)
{
    ShipName = name;
    ShipSize = size;
    shipAbrev = abrev;
    
}

void Ship::setHitCount(int hit)
{
    HitCount = hit;
}

void Ship::setHits(int hit)
{

}

void Ship::setIsSunk()
{

}

//getters

string Ship::getShipName()
{
    return ShipName;
}

int Ship::getShipSize()
{
    return ShipSize;
}

bool Ship::getIsSunk()
{
    return IsSunk;
}

int Ship::getHitCount()
{
    return HitCount;
}

char Ship::getShipAbrev()
{
    return shipAbrev;
}

int Ship::getShipXCoor(int index)
{
    return shipXCoor[index];
}

int Ship::getShipYCoor(int index)
{
    return shipYCoor[index];
}


bool Ship::isHit(int Xshot, int Yshot, bool GameStarted)
{
    for(int x = 0; x < ShipSize; x++)
    {
        if(shipXCoor[x] == Xshot && shipYCoor[x] == Yshot)
        {   
            if(GameStarted)
            {
                ShipHitsArray[x] = true;
                HitCount++;
                if(HitCount == ShipSize)
                {
                    IsSunk = true;
                }

            }//end nested if
            
            return true;

        }//end if 

    }//end for loop
    
    return false;
}