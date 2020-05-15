#include "GameBoard.h"
#include "Computer.h"
#include "Player.h"
#include "Ships.h"
#include <iostream>
using namespace std;


int main()
{   
       


        Player *ptrComputer;

        Computer Comp;

        Player *ptrComputer2;
        Computer Comp2;

        ptrComputer2 = &Comp2;


        ptrComputer = &Comp;

        

        ptrComputer->setShips();

        ptrComputer2->setShips();

        ptrComputer->displayBoard();
        cout << endl << endl;
        ptrComputer2->displayBoard();

        bool gameOver = false;
        do
        {      bool hit = false;
                int hitCount = 0;
                int missCount = 0;

                cout << "Computer is picking coordinates" << endl << endl;
                cout << "Computer has fired shot" << endl;
                cout << "Press enter to continue: ";
                cin.get();

                ptrComputer->setXY();
                cout << "Computer pick x is " << ptrComputer->getX() << " y is " << ptrComputer->getY() << endl;

                Comp2.FillASpot(ptrComputer->getX(),ptrComputer->getY());
                if(ptrComputer2->boardIsShipsHit(ptrComputer->getX(), ptrComputer2->getY()))
                {       
                        cout << "In computer hit Computer2's ship if statement" << " x is " << ptrComputer->getX() << " y is " << ptrComputer->getY() << endl;
                        hit = true;
                        Comp.setShipInArea(); // ship in area is true
                        Comp.setLocatedHit(hit);

                        hitCount++;
                        if(hitCount >= 2)
                        {
                                Comp.setLocatedHit(hit); //if count is 2 we have good direction
                        }
                        
                        
                        //Comp.setLocatedHit(hit);//located hit is true
                        Comp.setXhitCoor(ptrComputer->getX());
                        Comp.setYhitCoor(ptrComputer->getY());


                        cout << "computers x hit coordinate is " << Comp.getXhitCoor() << " y hit coor is " << Comp.getYhitCoor() << endl;

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
                
                cout << "COMPUTER 2 BOARDS" << endl;
                ptrComputer2->displayBoard();

                
                cout << endl << endl<< " prepare to select coordinates to fire on." << endl;

                cout << "Press any key to continue: ";
                cin.get();
                cout << endl << "--------------------" << endl;
                ptrComputer2->setXY();

                cin.ignore(); //lets cin.get work properly 

                
                cout << "Coordinates set press enter to fire: ";
                cin.get();

                if(ptrComputer->boardIsShipsHit(ptrComputer2->getX(), ptrComputer2->getY()))
                {       
                        hit = true;
                        ptrComputer2->displayBoard();

                        cout << "A hit marker X, has been placed on your board" << endl;
                }
                else
                {       
                        hit = false;
                        ptrComputer2->displayBoard();

                        cout << endl << "YOUR SHOT MISSED." << endl;
                        cout << "A miss marker O has been set on your board." << endl;

                }

                
                if(ptrComputer->isWinner())
                {
                        gameOver = true;
                }
                else if(ptrComputer2->isWinner())
                {
                        gameOver = true;
                }

    

        } while (!gameOver);
        
}

