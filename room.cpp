//////////////////////////////////////////////////////////////////
//room.cpp
//implementation of Room class
//This class holds a bunch of information about a room
//
//Author: Vivek Hegde
//Date: 5/31/2022
//////////////////////////////////////////////////////////////////

#include "room.h"

///////////////////////////////////////////////////////////////////////////////////
//Room class
///////////////////////////////////////////////////////////////////////////////////

//default
Room::Room(){
    this->roomNum = 99;
    this->hasBat = false;
    this->hasPit = false;
    this->hasWumpus = false;

    this->giantBat = Bat(99);
}

//constructor
Room::Room(int num){
    this->roomNum = num;
    this->hasBat = false;
    this->hasPit = false;
    this->hasWumpus = false;

    this->giantBat = Bat(num);
}

// operator =
Room &Room::operator=(const Room &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    this->roomNum = rhs.roomNum;
    this->hasBat = rhs.hasBat;
    this->hasPit = rhs.hasPit;
    this->hasWumpus = rhs.hasWumpus;
    this->isSafe = rhs.isSafe;
    this->giantBat = rhs.giantBat;

    return *this;
}

////////////////////////////////////////////////////////////
//createTunnels
//
//This function links this room to 3 other rooms
////////////////////////////////////////////////////////////

void Room::createTunnels(Room &t1, Room &t2, Room &t3){
    this->tunnel1 = &t1;
    this->tunnel2 = &t2;
    this->tunnel3 = &t3;
}

//places a bat in the room
void Room::placeBat(){
    this->hasBat = true;
}

//places a Wumpus in the room
void Room::placeWumpus(){
    this->hasWumpus = true;
}

//creates a pit in the room
void Room::createPit(){
    this->hasPit = true;
}

//sets the "safety" of the room
void Room::setSafe(){
    if(!hasBat && !hasPit && !hasWumpus){
        this->isSafe = true;
    }
    else this->isSafe = false;
}

//resets the health of the bat in the room back to '1 unit'
void Room::resetBatHealth(){
    this->giantBat.reset();
}

//increments the health of the bat by '1 unit'
void Room::incrementBatHealth(){
    this->giantBat.batHealth++;
}