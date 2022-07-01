//////////////////////////////////////////////////////////////////////////
//cave.h
//
//header file for Cave class
/////////////////////////////////////////////////////////////////////////

#ifndef CAVE_H
#define CAVE_H
#include "room.h"
#include "wumpus.h"
#include "adventurer.h"
#include "bat.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Cave
{
    public:
    //constructor
    Cave(int pits, int bats, int tirednessLvl);
    
    //destructor
    ~Cave();

    //connects the rooms in the cave
    void connectRooms();

    //populates the cave with bats
    void populateWithBats(int numOfBats);

    //creates pits
    void createPits(int numOfPits);

    //moves the wumpus
    void moveWupus(int rNum);

    //displaces the adventurer
    void moveAdventurer(int rNum);

    //The game itself
    void play();

    //updates bat health each turn
    void updateBatHealth();

    //updates wumpus tiredness
    void updateWumpusTiredness();

    //generates a random number between min and max  both inclusive
    int randomGen(int min, int max);

    //returns true if input is an adjacent room number or 20
    bool isAdjacentRoom(int choice, int r1, int r2, int r3, bool shoot);

    private:

    //array containing all the rooms
    Room *roomArray;

    //adventurer
    Adventurer adventurer;

    //wumpus
    Wumpus wumpus;

};

#endif
