#include "Board.h"
#include "Agent.h"
#include "Board.h"
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
internalBoard(board)
{
    health = 10;
    onFlag = true;
    agentCoord[0] = 0;
    agentCoord[1] = 0;
    entityChar = "@";
    viewRange = 1;
    numofPosMoves = 0;
}


Agent::Agent(int innitHealth, int spawn[2], Board& board): // maybe get constructor chaining
    internalBoard(board),
    health(innitHealth)
    {
        setAgentCoord(spawn);
        entityChar = "@";
        viewRange = 1;
        numofPosMoves = 0;
}

// INTERNAL HELPERS
// Set Coords
Agent& Agent::setAgentCoord(int coord[2]){
    agentCoord[0] = coord[0];
    agentCoord[1] = coord[1];
    return *this;
}

// Find Valid Moves
void Agent::GenerateValidMoves(int viewRange){
    numofPosMoves = 0;
    possibleMoves.clear();
    
    int lookCoord[2];
    for (int i = 0; i < 9; i++){ //i*viewRange
        lookCoord[0] = agentCoord[0] + lookViewRefTable[i][0];
        lookCoord[1] = agentCoord[1] + lookViewRefTable[i][1];
        std::cout << "tile contains " << internalBoard.getTile(lookCoord).containsSomething() << std::endl;
        if (!internalBoard.getTile(lookCoord).containsSomething()){
            possibleMoves.push_back(i);
            numofPosMoves++;
        }
    }
}



/// MOVE

/// RANDOM MOVE
int* Agent::randomMove(){
    // generate a valid random move based off of the line of sight
    GenerateValidMoves(viewRange);
    // create move();
    static int thismove[2];
    thismove[0] = agentCoord[0] + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][0];
    thismove[1] = agentCoord[1] + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][1];
    //std::cout << numofPosMoves << thismove[0] << thismove[1] << endl;
    return thismove;
}

/// MOVE
// update player position
void Agent::move(int coord[2]){
    agentCoord[0] = coord[0];
    agentCoord[1] = coord[1];
    // take in a direction,
    internalBoard.moveAgent(*this, coord);
}

/// EAT
void Agent::eat(Food somefood) {
    /// EatinternalBoard grant health proportional to value of Food
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
