#include "GameBoard.h"
#include "Computer.h"
#include "Player.h"
#include "Ships.h"
#include <iostream>
using namespace std;
void DisplayComputer();
void DisplayUserPrompt();

int main()
{       
        int misses = 0;

        Player *ptrComputer;
        Player *ptrComputer2;
        Computer Comp;
        Computer Comp2;
        ptrComputer2 = &Comp2;
        ptrComputer = &Comp;
/***************************************************************************/

        ptrComputer->setShips(); //sets Computer's ships
        ptrComputer2->setShips(); //set Computer 2's ships

        cout << "COMPUTER'S BOARD " << endl;
        ptrComputer->displayBoard();
        cout << endl << endl;
        cout << "COMPUTER 2'S BOARD"    << endl;
        ptrComputer2->displayBoard();


        bool gameOver = false;
/*****************************************************************************/
//START OF GAME*******
        do
        {       bool hit = false;
                int hitCount = 0;
                int missCount = 0;

                DisplayComputer(); //"computer is picking spots press enter to continue"

                
        /*this function sets the computer's x and y coordinates*/
                ptrComputer->setXY();

                //cout << "Computer chose Xinput " << ptrComputer->getX() << " Yinput " << ptrComputer->getY() << endl;



        /**********************************************************************************************************************/
                /*starts if statements to check if COMPUTER HIT computer 2's ship*/

                if(ptrComputer2->boardIsShipsHit(ptrComputer->getX(), ptrComputer->getY()))
                {       
                        cout << endl << endl << "In if     COMPUTER HIT Computer 2's SHIP!" << endl;

                        Comp2.FillASpot(ptrComputer->getX(), ptrComputer->getY(), 'H');
                        cout << "In if for Computer's shot hit.  Computers Xinput was " << ptrComputer->getX() << " Yinput was  " << ptrComputer->getY() << endl;
                        hit = true;

                        Comp.setShipInArea(); // ship in area is true

                        hitCount++;
                        Comp.setHitCount(hitCount);

                        /*if(hitCount >= 2) // TRY IF HIT COUNT IS GREATER THAN 5
                        {
                                Comp.setLocatedHit(hit); //if count is 2 we have good direction
                        }*/
                        
                        //Comp.setLocatedHit(hit);//located hit is true
                        Comp.setXhitCoor(ptrComputer->getX());
                        Comp.setYhitCoor(ptrComputer->getY());

                        cout << "computers XhitCoor is " << Comp.getXhitCoor() << " YhitCoor is " << Comp.getYhitCoor() << endl;
                        cout << "Computers shipInArea is " << Comp.getShipInArea() << endl << endl;
                        cout << "Computers hit count is " << hitCount << endl << endl;
                        cout << "Computers hit count is " << Comp.getHitCount() << endl;
                        cout << "Computer mis count is " << Comp.getMissCount() << endl;

                }
                else
                {       
                        Comp2.FillASpot(ptrComputer->getX(),ptrComputer->getY(), 'O'); //fills comp2's board with computer's shots

                        cout << endl << endl << "In else    COMPUTER SHOT MISSED" << endl << endl;

                        cout << "Marked computers miss on computer 2's board. " << endl << endl;
                        cout << "Computer Xinput shot was " << ptrComputer->getX() << " Yinput shot was " << ptrComputer->getY() << endl << endl;
                        cout << "Computer's XhitCoor is " << Comp.getXhitCoor() << " YhitCoor is " << Comp.getYhitCoor() << endl;
                        //if else hit was false
                        hit = false;
                        cout << "Computer's hit count is " << Comp.getHitCount() << endl << endl;
                        if(Comp.getShipInArea())
                        {
                                missCount++;
                                Comp.setMissCount(missCount);
                        }
                        cout << "Computers miss count is " << Comp.getMissCount();

                }
        /**************************************************************************************************************/

                cout << "COMPUTER 2 BOARDS" << endl;
                ptrComputer2->displayBoard();

                cout << endl << endl;

                
               /* //displays coordinates set press enter to continue
                        DisplayUserPrompt();

                ptrComputer2->setXY();/*sets computer 2's x and y;

                cout << "Coordinates set press enter to fire: ";
                cin.get();

/***********************************************************************************************************
//if statements to check if COMPUTERS'S SHIPS were hit 
                if(ptrComputer->boardIsShipsHit(ptrComputer2->getX(), ptrComputer2->getY()))
                {       

                        //hit = true;
                        //ptrComputer2->displayBoard();
                        //cout << "A hit marker X, has been placed on your board" << endl;
                }
                else
                {       
                       // hit = false;
                       // ptrComputer2->displayBoard();

                        cout << endl << "YOUR SHOT MISSED." << endl;
                        cout << "A miss marker O has been set on your board." << endl;
                }

/********************************************************************************************************/
//check for a winner
                /*if(ptrComputer->isWinner())
                {
                        gameOver = true;
                }
                else if(ptrComputer2->isWinner())
                {
                        gameOver = true;
                }*/

        } while (!gameOver);
        
}

void DisplayComputer()
{
        cout << "Computer is picking coordinates" << endl << endl;
                cout << "Computer has fired shot" << endl;
                cout << "Press enter to continue: ";
                cin.get();
                cout << endl << endl;
}

void DisplayUserPrompt()
{
        cout << endl << endl<< " prepare to select coordinates to fire on." << endl;

                cout << "Press any key to continue: ";
                cin.get();
                cout << endl << "--------------------" << endl;
}