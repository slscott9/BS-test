#ifndef SHIPS_H
#define SHIPS_H
#include <string>
#include <vector>
#define MAXNUMSHIPS 5

class Ship
{
    private:
    //ship characteristics
        std::string ShipName;
        char shipAbrev;
        int ShipSize;

    //ship location X and Y
        int shipXCoor[MAXNUMSHIPS];
        int shipYCoor[MAXNUMSHIPS];

    //ship damage
        bool ShipHitsArray[MAXNUMSHIPS];
        bool IsSunk;
        int HitCount;

    public:
    //constructor
        Ship();
        Ship(std::string , char, int);

    //setters
        void setCoor(int, int, int);//sets the coordinate array to input for a ship

        void setAll(std::string, char, int);

        void setHitCount(int); //keep in ships

        void setHits(int);//keep in ships
        
        void setIsSunk(); //keep in ships
        
    //getters
        std::string getShipName();

        int getShipSize(); //keep

        bool getIsSunk(); //keep

        int getHitCount(); //keep

        char getShipAbrev();

        int getShipXCoor(int);

        int getShipYCoor(int);
        
    //function to check if a hit
                                bool isHit(int , int, bool);

};

#endif