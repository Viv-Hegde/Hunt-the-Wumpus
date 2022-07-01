//////////////////////////////////////////////////////////////
//driver.cpp
//This file is the driver class for the game
//
//AUTHOR: Vivek Hegde
//Date: 5/31/2022
//////////////////////////////////////////////////////////////

#include "cave.h"
#include <iostream>

using namespace std;

main(int argc, char **argv ){
    if( argc !=4 ){
        cout<< "Incorrect number of parameters.  Provide  <NumBats>, <NumPits>, <WumpusHealth> "<<endl;
        return (-1);
    }
    
    int numBats = stoi(argv[1]);
    int numPits = stoi(argv[2]);
    int wumpusTiredness = stoi(argv[3]);


    //validate inputs
    //exits if invalid user input

    //bats
    if(numBats<0 || numBats>=20){
        cout<<"INVALID: <numBats> should at least be 0 and less than 20"<<endl;
        exit(0);
    }

    //pits
    if(numPits<0 || numPits>=20){
        cout<<"INVALID: <numPits> should at least be 0 and less than 20"<<endl;
        exit(0);
    }    

    //wumpusTiredness
    if(wumpusTiredness <0){
        cout<<"INVALID: <WumpusTiredness> should at least be 0"<<endl;
        exit(0);
    }

    Cave huntTheWumpus (numPits,numBats,wumpusTiredness);
    huntTheWumpus.play();

}

