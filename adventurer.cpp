///////////////////////////////////////////////////////////////
//adventurer.cpp
//
//implementation of Adventurer class
//Author: Vivek Hegde
//date:
///////////////////////////////////////////////////////////////

#include "adventurer.h"

///////////////////////////////////////////////////////////////////////////////////
//Adventurer class
///////////////////////////////////////////////////////////////////////////////////

Adventurer::Adventurer(){
    this->roomNum = 0;
    this->arrow = 2;
    this->isAlive = true;
}

//shoots an arrow reducing the arrow count by 1
void Adventurer::shootArrow(){
    if(arrow>0){
        arrow--;
    }
}