/////////////////////////////////////////////////////////////////////////////////////////
//adventurer.h
//
//Header file for adventurer class
////////////////////////////////////////////////////////////////////////////////////////

#ifndef ADVENTURER_H
#define ADVENTURER_H

class Adventurer{
    friend class Cave;

    //default
    Adventurer();

    //shoots an arrow
    void shootArrow();

    private:
    //Adventurer room number
    int roomNum;

    //contains arrows
    int arrow;

    //true of adventurer is alive
    bool isAlive;

};
#endif