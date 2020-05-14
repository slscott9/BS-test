#include "GameBoard.h"
#include "Human.h"
#include "Computer.h"
#include "Player.h"
#include "Ships.h"
#include <iostream>
using namespace std;


int main()
{   
        string name;

        Player *ptrPlayer, *ptrComputer;

        Human PlayerOne;
        Computer Comp;

        ptrPlayer = &PlayerOne;
        ptrComputer = &Comp;


        cout << setw(16) << "BATTLESHIP" << endl;
        cout << setw(16) <<  "******************************" << endl;
        cout << "SHIP TYPES " << endl << endl;
                cout << "-----------------" << endl;

        cout << setw(10) << "Carrier " << endl;
        cout << "Size: " << 5 << endl;
        cout << "Board abreviation: C " << endl << endl;
        cout << "-----------------" << endl;

        cout << setw(10) << "Battle ship " << endl;
        cout << "Size: 4" << endl;
        cout << "Board abreviation: B" << endl;
        cout << "-----------------" << endl;

        cout << setw(10) << "Destroyer " << endl;
        cout << "Size: 3" << endl;
        cout << "Board abreviation: D" << endl;
        cout << "-----------------" << endl;

        cout << setw(10) << "Submarine " << endl;
        cout << "Size: 3" << endl;
        cout << "Board abreviation: S" << endl;
                cout << "-----------------" << endl;

        cout << setw(10) << "Patrol Boat " << endl;
        cout << "Size: 2" << endl;
        cout << "Board abreviation: P" << endl << endl;
                cout << "-----------------" << endl;



        cout << "Player one enter your name: ";
        getline(cin,name);

        PlayerOne.setPlayerName(name);

        
//sets up players ships and computer ships
        ptrPlayer->displayBoard();

        cout << endl << endl << "You will be asked to enter each ships coordinates on the board ";
        cout << endl << "Press enter key to begin: ";
        cin.get();
        cout << endl << endl;

        ptrPlayer->setShips();
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout << "The computer will now set it's ships, press enter to continue: ";
        cin.get();

        ptrComputer->setShips();
        ptrComputer->displayBoard();

        cin.ignore();
        cout << endl;
        cout << "*COMPUTER SHIPS SET*" << endl;
        cout << "**READY FOR WAR** " << endl;
        cout << "-----------------------------------------------------------------------------------" << endl << endl;

        cout << "The computer will shoot first, if its shot is a hit, your ship will be marked with an H" << endl;
        cout << "Your hits on the computer's ships will be marked as an X." << endl;
        cout << "Your misses will be marked as an O" << endl << endl;

        cout << "Press enter to begin: ";
        cin.get();

        bool gameOver = false;

        do
        {      bool hit = false;
                int hitCount = 0;
                cout << "Computer is picking coordinates" << endl << endl;
                cout << "Computer has fired shot" << endl;
                cout << "Press enter to continue: ";
                cin.get();

                ptrComputer->setXY();
                if(ptrPlayer->boardIsShipsHit(ptrComputer->getX(), ptrComputer->getY()))
                {       
                        cout << "In computer hit your ship if" << " x is " << ptrComputer->getX() << " y is " << ptrComputer->getY() << endl;
                        hit = true;
                        Comp.setShipInArea(); // ship in area is true
                        hitCount++;
                        if(hitCount == 2)
                        {
                                Comp.setLocatedHit(hit); //if count is 2 we have good direction
                        }
                        
                        //Comp.setLocatedHit(hit);//located hit is true
                        Comp.setXhitCoor(ptrComputer->getX());
                        Comp.setYhitCoor(ptrComputer->getY());
                        cout << endl << endl << "COMPUTER HIT YOUR SHIP!" << endl;
                }
                else
                {       
                        //if else hit was false
                        hit = false;
                        Comp.setLocatedHit(hit);//located hit is false

                        cout << endl << endl << "COMPUTER SHOT MISSED" << endl;
                }
                
                        //Comp.setXleft(hit); //x left set to false
                        //Comp.setXright(hit);
                        //Comp.setYdown(hit);
                        //Comp.setYup(hit);

                ptrPlayer->displayBoard();

                cout << endl << endl << PlayerOne.getPlayerName() << " prepare to select coordinates to fire on." << endl;

                cout << "Press any key to continue: ";
                cin.get();
                cout << endl << "--------------------" << endl;
                ptrPlayer->setXY();

                cin.ignore(); //lets cin.get work properly 

                
                cout << "Coordinates set press enter to fire: ";
                cin.get();

                if(ptrComputer->boardIsShipsHit(ptrPlayer->getX(), ptrPlayer->getY()))
                {       
                        hit = true;
                        PlayerOne.setHitMarker(ptrPlayer->getX(), ptrPlayer->getY(), hit);
                        ptrPlayer->displayBoard();

                        cout << endl << "COMPUTER SHIP HIT: " << PlayerOne.getLetter() << ", " << ptrPlayer->getY() << endl;

                        cout << "A hit marker X, has been placed on your board" << endl;
                }
                else
                {       
                        hit = false;
                        PlayerOne.setHitMarker(ptrPlayer->getX(), ptrPlayer->getY(), hit);
                        ptrPlayer->displayBoard();

                        cout << endl << "YOUR SHOT MISSED." << endl;
                        cout << "A miss marker O has been set on your board." << endl;

                }

                
                if(ptrComputer->isWinner())
                {
                        gameOver = true;
                }
                else if(ptrPlayer->isWinner())
                {
                        gameOver = true;
                }

    

        } while (!gameOver);
        
  
}

