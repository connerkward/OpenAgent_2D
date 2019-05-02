#include "Board.h"
#include "Agent.h"
#include <cstdlib>
using namespace std;

// Look Up Table for Line of Sight
// Please Replace with algorithm math man
const int Agent::lookViewRefTable[9][2] =  {{-1,-1,},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};
// this is 0 to 9 of all the direction vectors from top left, left to right (the origin is the top left).
//which of course, for consistency is of course an array and not a vector. genius

// CONSTRUCTOR
// update spawn, health, and internal reference to board
Agent::Agent(Board& board):
internalboard(board)
{
    health = 10;
    onFlag = true;
    agentCoord[0] = 0;
    agentCoord[1] = 0;
    entityChar = "@";
    //populateLos(1);
}


Agent::Agent(int innitHealth, int spawn[2], Board& board): // maybe get constructor chaining
    internalboard(board),
    health(innitHealth)
    {
    agentCoord[0] = spawn[0];
    agentCoord[1] = spawn[1];
    entityChar = "@";
    //populateLos(1);
}

// Populate LOS
void Agent::populateLos(int viewRange){
    for (int i = 0; i < 10; i++){
        int coords[2];
        coords[0] = agentCoord[0] + lookViewRefTable[i][0]*viewRange;
        coords[1] = agentCoord[0] + lookViewRefTable[i][1]*viewRange;
        //lineOfSight[i] = internalboard.getTile(coords); // the final piece of pie
    }
}

Agent& Agent::setCoord(int coord[2]){
    agentCoord[0] = coord[0];
    agentCoord[1] = coord[1];
    return *this;
}

/// MOVE
// update player position
void Agent::move(int coord[2]){
    agentCoord[0] = coord[0];
    agentCoord[1] = coord[1];
    // take in a direction,
    internalboard.moveAgent(*this, coord);
}

/// RANDOM MOVE
void Agent::randomMove(){
    //populateLos(1);
    int coord[2];
    std::srand(time(0));
    int rand = (std::rand() % 9);
    coord[0] = agentCoord[0] + lookViewRefTable[rand][0];
    coord[1] = agentCoord[1] + lookViewRefTable[rand][1];
    std::cout << "going to" << agentCoord[0] << agentCoord[1] << std::endl;
    move(coord);
}


/// EAT

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
