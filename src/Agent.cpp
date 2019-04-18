#include "Food.h"
#include<iostream>
#include "Agent.h"
#include "Board.h"
using namespace std;

// Constructor
// param health, spawn and reference to board
// update spawn, health, and internal reference to board
Agent::Agent(int innitHealth, int innitplayercord[2], Board& b): internalboard(b){
    //             some things must be done this way        ^
    health = innitHealth;
    playercord[0] = innitplayercord[0];
    playercord[1] = innitplayercord[1];
}

/// EAT
// param somefod item, update health
void Agent::eat(Food somefood) {
    /// Eating Food will grant health proportional to value of Food
    health = somefood.healthgain;
    return;
}

/// MOVE
// param direction vector, update player position
void Agent::move(int direction[2]) {
    // param is direction to move,
    //ie [-1,-1] (left and down even if 0,0 is in top left corner)
    playercord[0] += direction[0];
    playercord[1] += direction[1];
    return;
}

/// RANDOM MOVE
// update player position randomly
void Agent::randomMove() {
    bool findingmove = true;
    while(findingmove == true){
        // GENERATE RANDOM LOCATION
        int xmove = playercord[0] - rand()%2;
        int ymove = playercord[1] - rand()%2;
        int vec[2];
        vec[0] = xmove;
        vec[1] = ymove;
        
        // IF OBSTACLE COLLISION
        if(internalboard.checkifvalid(vec)){ // checks if "empty" or stepable item
            auto res = internalboard.check(vec); // is suppossed to return a reference to whatever object is in the spot, "auto" determines its type for now
            if(res == "food"){// string comparison for now, hopefully some sort of object comparison in the future
                //eat(res);
                Agent::move(vec);
                break;
            }
            else if(res == "obstacle"){
                return; // if obstacle do nothing and try to find other random direction
            }
            else{
                return;
            }
        }
    }
    return;
}

/// AGE
// Such is life, in the enderverse.
bool Agent::age() {
    health -= 1;
    if (health < 0){
        return false;
    }
    else{
        return true;
    }
}
