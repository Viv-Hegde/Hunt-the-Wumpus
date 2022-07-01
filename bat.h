/////////////////////////////////////////////////////////////////////////////////////////
//bat.h
//
//Header file for bat class
////////////////////////////////////////////////////////////////////////////////////////

#ifndef BAT_H
#define BAT_H

class Bat
{
    friend class Room;
    friend class Cave;

    //default
    Bat();

    //constructor
    Bat(int rNum);

    //operator =
    Bat & operator = (const Bat &);

    //resets health
    void reset();

    //returns the number of rooms the bat can carry the adventurer
    int numOfRooms();

    private:
    //health
    int batHealth;

    //room Number
    int roomNum;
};


#endif