//////////////////////////////////////////////////////////////////
//bat.cpp
//
//implementation of Bat class
//Author: Vivek Hegde
//Date: 5/31/2022
//////////////////////////////////////////////////////////////////

#include "bat.h"

///////////////////////////////////////////////////////////////////////////////////
//Bat class
///////////////////////////////////////////////////////////////////////////////////

//default
Bat::Bat(){
    this->batHealth = 1;
    this->roomNum = 99;
}

//constructor
Bat::Bat(int rNum){
    this->batHealth = 1;
    this->roomNum = rNum;
}

// operator =
Bat &Bat::operator=(const Bat &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    this->batHealth = rhs.batHealth;
    this->roomNum = rhs.roomNum;

    return *this;
}

//resets the Bat's health to 1 unit
void Bat::reset(){
    this->batHealth = 1;
}

/////////////////////////////////////////////////////////////////
//numOfRooms()
//
//The number of rooms the bat can carry the adventurer
//returns an integer
//////////////////////////////////////////////////////////////////

int Bat::numOfRooms(){
    return (batHealth % 3)+1;
}