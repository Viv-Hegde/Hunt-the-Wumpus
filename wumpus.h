/////////////////////////////////////////////////////////////////////////////////////////
//wumpus.h
//
//Header file for wumpus class
////////////////////////////////////////////////////////////////////////////////////////

#ifndef WUMPUS_H
#define WUMPUS_H
#include <stdlib.h>
#include <time.h>

class Wumpus{
    friend class Cave;

    //default
    Wumpus();

    //constructor
    Wumpus(int rNum, int tLvl);

    //operator =
    Wumpus & operator = (const Wumpus &);

    //returns true if the wumpus decides to eat
    bool decissionToEat();

    private:
    //Wumpus room number
    int roomNum;

    //Wumpus tiredness level
    int tiredness;
    
};
#endif