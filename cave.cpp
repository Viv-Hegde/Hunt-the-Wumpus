/////////////////////////////////////////////////////////////////////////////////
//cave.cpp
//
//implementation of Cave class
//The cave holds all the rooms and drives everything that happens in a round
//Author: Vivek Hegde
//Date: 5/31/2022
/////////////////////////////////////////////////////////////////////////////////

#include"cave.h"

///////////////////////////////////////////////////////////////////////////////////
//Cave class
///////////////////////////////////////////////////////////////////////////////////


//constructor
Cave::Cave(int pits, int bats, int tirednessLvl){
    roomArray = new Room[20];  //use array to hold rooms as size is fixed

    for(int i=0; i<20; i++){
        Room newRoom(i);
        roomArray[i] = newRoom;
    }

    connectRooms();           //connect the rooms in the form of a Dodecahedron
    
    srand(time(NULL));        //seeding for generating a random number

    populateWithBats(bats);    //randomly populate the cave with bats
    createPits(pits);          //randomly create pits in some rooms

    int wRoom = randomGen(1,19);
    wumpus = Wumpus(wRoom,tirednessLvl);
    roomArray[wumpus.roomNum].hasWumpus = true;        //place the Wumpus in the cave

    cout<<"\nFOR TESTING: Putting Wumpus in Room "<<wumpus.roomNum<<endl<<endl;

    //At this point our structure is set up
    //set the safety of each room in a cave depending on what's inside the room
    for(int i=0; i<20; i++){
        roomArray[i].setSafe();
    }

    adventurer = Adventurer();
}

//destructor
Cave::~Cave(){
    delete roomArray;
}

//generate a random number
int Cave::randomGen(int min, int max){
    return rand()%(max-min+1)+min;
}

///////////////////////////////////////////////////////////
//connectRooms()
//
//connects all the rooms in the cave
////////////////////////////////////////////////////////////

void Cave::connectRooms(){
    //Room arrangement in a specific order
    roomArray[1].createTunnels(roomArray[2],roomArray[8],roomArray[5]);
    roomArray[2].createTunnels(roomArray[3],roomArray[10],roomArray[1]);
    roomArray[3].createTunnels(roomArray[4],roomArray[12],roomArray[2]);
    roomArray[4].createTunnels(roomArray[5],roomArray[14],roomArray[3]);
    roomArray[5].createTunnels(roomArray[6],roomArray[1],roomArray[4]);
    roomArray[6].createTunnels(roomArray[7],roomArray[15],roomArray[5]);
    roomArray[7].createTunnels(roomArray[8],roomArray[17],roomArray[6]);
    roomArray[8].createTunnels(roomArray[9],roomArray[1],roomArray[7]);
    roomArray[9].createTunnels(roomArray[10],roomArray[18],roomArray[8]);
    roomArray[10].createTunnels(roomArray[11],roomArray[2],roomArray[9]);
    roomArray[11].createTunnels(roomArray[12],roomArray[19],roomArray[10]);
    roomArray[12].createTunnels(roomArray[13],roomArray[3],roomArray[11]);
    roomArray[13].createTunnels(roomArray[14],roomArray[20],roomArray[12]);
    roomArray[14].createTunnels(roomArray[15],roomArray[4],roomArray[13]);
    roomArray[15].createTunnels(roomArray[16],roomArray[6],roomArray[14]);
    roomArray[16].createTunnels(roomArray[17],roomArray[20],roomArray[15]);
    roomArray[17].createTunnels(roomArray[18],roomArray[7],roomArray[16]);
    roomArray[18].createTunnels(roomArray[19],roomArray[9],roomArray[17]);
    roomArray[19].createTunnels(roomArray[0],roomArray[11],roomArray[18]);
    roomArray[0].createTunnels(roomArray[16],roomArray[13],roomArray[19]);
}

/////////////////////////////////////////////////////////////
//populateWithBats(x)
//
//Randomly populates the 'x' rooms in the cave with bats
/////////////////////////////////////////////////////////////

void Cave::populateWithBats(int numOfBats){
    for(int i=0; i<numOfBats; i++){
        int randomRoomNumber;
        do{
            randomRoomNumber = randomGen(1,19);
        }
        while(roomArray[randomRoomNumber].hasBat);

        roomArray[randomRoomNumber].placeBat();
    }
}

///////////////////////////////////////////////////
//createPits(x)
//
//Randomly creates pits in 'x' rooms of the cave
////////////////////////////////////////////////////

void Cave::createPits(int numOfPits){
    for(int i=0; i<numOfPits; i++){
        int randomRoomNumber;
        do{
            randomRoomNumber = randomGen(1,19);
        }
        while(roomArray[randomRoomNumber].hasPit);

        roomArray[randomRoomNumber].createPit();
    }
}

////////////////////////////////////////////////////////////
//moveWumpus()
//
//moves the wumpus to a different room
///////////////////////////////////////////////////////////

void Cave::moveWupus(int rNum){
    roomArray[wumpus.roomNum].hasWumpus = false;
    roomArray[wumpus.roomNum].setSafe();
    wumpus.roomNum = rNum;
    roomArray[wumpus.roomNum].hasWumpus = true;
    roomArray[wumpus.roomNum].setSafe();
    cout<<"\nFOR TESTING: Wumpus has moved to Room "<<wumpus.roomNum<<endl;
}

////////////////////////////////////////////////////////////
//moveAdventurer()
//
//moves the adventuer to a different room
///////////////////////////////////////////////////////////

void Cave::moveAdventurer(int rNum){
    adventurer.roomNum = rNum;
}

/////////////////////////////////////////////////////////////
//updateBatHealth()
//
//increments the health of the bats in the rooms by 1 unit
/////////////////////////////////////////////////////////////

void Cave::updateBatHealth(){
    for(int i=0; i<20; i++){
        if(roomArray[i].hasBat){
            roomArray[i].incrementBatHealth();
        }
    }
}

/////////////////////////////////////////////////////////////
//updateWumpusTiredness()
//
//decreases wumpus tiredness by 1 unit
/////////////////////////////////////////////////////////////

void Cave::updateWumpusTiredness(){
    if(wumpus.tiredness > 0){
        wumpus.tiredness--;
    }
}

//////////////////////////////////////////////////////////////
//isAdjacentRoom
//
// returns true if the user enters a room choice that is
// adjacent to the current room
//////////////////////////////////////////////////////////////

bool Cave::isAdjacentRoom(int choice, int r1, int r2, int r3, bool shoot){
    if(!shoot){
        if(choice == 20) return true;
    }
    if(choice == r1) return true;
    if(choice == r2) return true;
    if(choice == r3) return true;
    return false;
}

/////////////////////////////////////////////////////////////
//play()
//
//This method drives what happens in each round of the game
//play until the adventurer is dead or runs out of arrows
/////////////////////////////////////////////////////////////

void Cave::play(){
    while(adventurer.isAlive && adventurer.arrow > 0){

        //Announce current room at the begining of each round
        cout<<"You are in room "<<adventurer.roomNum<<endl;

        //Events that happen if the adventurer is in a "safe" room
        if (roomArray[adventurer.roomNum].isSafe){            

            int r1 = roomArray[adventurer.roomNum].tunnel1->roomNum;
            int r2 = roomArray[adventurer.roomNum].tunnel2->roomNum;
            int r3 = roomArray[adventurer.roomNum].tunnel3->roomNum;

            if(roomArray[r1].hasBat || roomArray[r2].hasBat || roomArray[r3].hasBat){
                cout<<"You hear the wings of a bat fluttering "<<endl;
            }
            if(roomArray[r1].hasPit || roomArray[r2].hasPit || roomArray[r3].hasPit){
                cout<<"You feel a cold draft "<<endl;
            }
            if(roomArray[r1].hasWumpus || roomArray[r2].hasWumpus || roomArray[r3].hasWumpus){
                cout<<"You smell a Wumpus nearby "<<endl;
            }

            cout<<"You may go to Room "<<r1<<", "<<r2<<", "<<r3<<endl;
            cout<<"Enter your choice: ";

            int choice;
            cin>>choice;

            //Special case: quick exit
            if(choice == -1){
                cout<<"\n\n*****END******"<<endl;
                exit(0);
            }
            
            //handle other user inputs
            while (!isAdjacentRoom(choice,r1,r2,r3,false)){
                cout<<endl<<"Enter a valid choice: ";
                cin>>choice;
            }
            
            //Shoot into another room
            if(choice == 20){
                int shootRoom;
                cout<<endl<<"What direction do you want to shoot your arrow? "<<endl;
                cout<<"Enter Room number: ";
                cin>>shootRoom;
                adventurer.shootArrow();

                //invalid room
                if(!isAdjacentRoom(shootRoom,r1,r2,r3,true)){
                    cout<<"The arrow hit a wall and broke."<<endl;
                }
                else{
                //correct room with thw wumpus
                    if(shootRoom == wumpus.roomNum){
                        cout<<endl<<"\nYou have killed the Wumpus.  You win."<<endl;
                        exit(0);
                    }

                    else{
                        //Wumpus not there
                        cout<<"You fired but didn't hit anything."<<endl;
                    }                   
                }
                //announce arrows remaining
                cout<<endl<<"Arrows remaining: "<<adventurer.arrow<<endl;
                
            }

            //no arrows remaining
            if(adventurer.arrow==0){
                cout<<endl<<"\nYou have used up all your arrows. You are dead. "<<endl;
                adventurer.isAlive = false;
                exit(0);
            }

            cout<<endl;
            if(choice != 20){
                moveAdventurer(choice);
            }

            //TIME PASSES
            updateBatHealth();
            updateWumpusTiredness();
            
        }
        else
        {   //events that happen if the room is NOT safe

            //handle if the room has a bat
            if(roomArray[adventurer.roomNum].hasBat){

                int currRoom = adventurer.roomNum;
                int distance = roomArray[adventurer.roomNum].giantBat.numOfRooms();
                while(distance > 0){
                    int randomRoom = randomGen(1,3);

                    if(randomRoom == 1){
                        moveAdventurer(roomArray[adventurer.roomNum].tunnel1->roomNum);
                    }
                    else if (randomRoom == 2){
                        moveAdventurer(roomArray[adventurer.roomNum].tunnel2->roomNum);
                    }
                    else{
                        moveAdventurer(roomArray[adventurer.roomNum].tunnel3->roomNum);
                    }

                    distance--;                    
                }

                cout<<"A giant bat picks you up and drops you in Room "<<adventurer.roomNum<<endl;

                //TIME PASSES
                updateBatHealth();
                updateWumpusTiredness();

                //reset the health of the bat that carried the adventurer
                roomArray[currRoom].resetBatHealth();
            }

            //Handle if the room has a pit
            else if(roomArray[adventurer.roomNum].hasPit){
                cout<<"You have fallen into a pit.  You are dead"<<endl;
                adventurer.isAlive = false;
                exit(0);
            }

            //Handle if the room has a Wumpus
            else if(roomArray[adventurer.roomNum].hasWumpus){
                if(wumpus.decissionToEat()){  //Wumpus decides to eat based on tiredness
                    cout<<"You disturbed the wumpus and it ate you. You are dead"<<endl;
                    adventurer.isAlive = false;
                    exit(0);
                }
                else{
                    cout<<"You disturbed the wumpus but it wandered off to another room"<<endl;
                    int currRoom = adventurer.roomNum;

                    int diffRoom;

                    do
                    {
                        diffRoom = randomGen(0,19);
                    } while (diffRoom == currRoom);

                    moveWupus(diffRoom);
                    cout<<endl;

                    //TIME PASSES
                    updateBatHealth();
                    updateWumpusTiredness();
                    
                }
            }
        }
        
    }
}