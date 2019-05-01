#include "Agent.h"
using namespace std;

// Look Up Table for Line of Sight
// Please Replace with algorithm math man
const int Agent::lookViewRefTable[9][2] = {{-1,-1,},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};

// CONSTRUCTOR
// update spawn, health, and internal reference to board
Agent::Agent(Board& board):
internalboard(board)
{
    health = 10;
    onFlag = true;
    playercord[0] = 0;
    playercord[1] = 0;
    entityChar = "@";
    populateLos(1);
}


Agent::Agent(int innitHealth, int spawn[2], Board& board):
    internalboard(board),
    health(innitHealth)
    {
    playercord[0] = spawn[0];
    playercord[1] = spawn[1];
    entityChar = "@";
    populateLos(1);
}

// Populate LOS
void Agent::populateLos(int viewRange){
    for (int i = 0; i < 10; i++){
        int coords[2];
        coords[0] = lookViewRefTable[i][0]*viewRange;
        coords[1] = lookViewRefTable[i][1]*viewRange;
        //lineOfSight[i] = internalboard.?; // the final piece of pie
    }
}

/// MOVE
// update player position
void Agent::move(int direction[2]){
    // take in a direction, send its move over to board
}

/// RANDOM MOVE
void Agent::randomMove(){
    //
}


/// EAT
// param somefod item, update health
void Agent::eat(Food somefood) {
    /// Eating Food will grant health proportional to value of Food
    health = somefood.healthgain;
    return;
}

/// AGE
bool Agent::age() {
    health -= 1;
    if (health < 0){
        return false;
    }
    else{
        return true;
    }
}
