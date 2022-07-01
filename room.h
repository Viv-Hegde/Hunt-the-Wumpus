/////////////////////////////////////////////////////////////////////////////////////////
//room.h
//
//Header file for room class
////////////////////////////////////////////////////////////////////////////////////////


#ifndef ROOM_H
#define ROOM_H
#include "bat.h"

class Room
{
    friend class Cave;

    //default
    Room();

    //constructor
    Room(int num);

    //operator =
    Room & operator = (const Room &);

    //connects rooms
    void createTunnels(Room &t1, Room &t2, Room &t3);

    //places a giant bat in the room
    void placeBat();

    //creates a pit in the room
    void createPit();

    //places the wumpus in the room
    void placeWumpus();

    //sets the safety of the room
    void setSafe();

    //resets the Bat's health
    void resetBatHealth();

    //increases the Bat's health
    void incrementBatHealth();


    private:

    //room number
    int roomNum;

    //true if the room contains a Pit
    bool hasPit;

    //true if the room contains a Bat
    bool hasBat;

    //true if the room contains a Wumpus
    bool hasWumpus;

    //true if the room does NOT contain a Pit, a Bat, and a Wumpus
    bool isSafe;

    //Tunnels to other rooms
    Room *tunnel1;
    Room *tunnel2;
    Room *tunnel3;

    //Bat in the room
    Bat giantBat;

};
#endif
