/////////////////////////////////////////////////////////////////
//wumpus.cpp
//
//implementation of Wumpus class
//Author: Vivek Hegde
//Date: 5/31/2022
/////////////////////////////////////////////////////////////////

#include "wumpus.h"

///////////////////////////////////////////////////////////////////////////////////
//Wumpus class
///////////////////////////////////////////////////////////////////////////////////

//default
Wumpus::Wumpus(){
    srand(time(NULL));
    this->roomNum = 99;
    this->tiredness = 0;
}

//constructor
Wumpus::Wumpus(int rNum, int tLvl){
    srand(time(NULL));
    this->roomNum = rNum;
    this->tiredness = tLvl;
}

// operator =
Wumpus &Wumpus::operator=(const Wumpus &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    this->roomNum = rhs.roomNum;
    this->tiredness = rhs.tiredness;

    return *this;
}

/////////////////////////////////////////////////////////////
//decissionToEat()
//
//Returns true if the Wumpus decides to eat the adventurer
//
//Thw wumpus eats the adventurer if it is not tired 
//OR random number generated is 0
/////////////////////////////////////////////////////////////

bool Wumpus::decissionToEat(){
    //cout<<"Tiredness: "<<tiredness<<endl;
    if(tiredness==0){
        return true;
    }
    
    int r = rand()%(tiredness+1);
    if(r==0){
        return true;
    }
    else{
        //cout<<"decission number generated: "<<r<<endl;
        return false;
    }
     
}