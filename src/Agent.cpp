#include "Agent.h"
#include <cstdlib>
#include "Environment.hpp"
using namespace std;

// Look Up Table for Line of Sight
// Please Replace with algorithm math man
const int Agent::lookViewRefTable[9][2] =  {{-1,-1,},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};

// CONSTRUCTOR
// update spawn, health, and internal reference to board
Agent::Agent(Environment& board):
Entity(board)
{
    health = 10;
    entityChar = "@";
    viewRange = 1; // default 
    numofPosMoves = 0;
}

// INTERNAL HELPERS
// Find Valid Moves
void Agent::GenerateValidMoves(int viewRange){
    numofPosMoves = 0;
    this->possibleMoves.clear();
    int lookCoord[2];
    for (int curRange = 1; curRange <= viewRange; curRange++){
        for (int i = 0; i < 9; i++){
            lookCoord[0] = coord[0] + lookViewRefTable[i][0] * curRange;
            lookCoord[1] = coord[1] + lookViewRefTable[i][1] * curRange;
            if (internalBoard.getTileAt(lookCoord).containsSomething()){
                // Tile Has Object of Interest, Food
                if (internalBoard.getTileAt(lookCoord).containsFood()){
    
                    possibleMoves.clear();
                    possibleMoves.push_back(i);
                    numofPosMoves++;
                    break;
                }
            }
            else{ // Tile is empty
                possibleMoves.push_back(i);
                numofPosMoves++;
            }
        }
    }
}

/// MOVE
/// RANDOM MOVE
int* Agent::randomMove(){
    // generate a valid random move based off of the line of sight
    GenerateValidMoves(viewRange);
    // create default move at  0,0;
    static int thismove[2] = {0,0};
    if (numofPosMoves < 1){
        // return zero move
        return thismove;
    }
    else{
        // return random from possible moves array
        thismove[0] = coord[0] + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][0];
        thismove[1] = coord[1] + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][1];
        return thismove;
    }
}

/// EAT
void Agent::eat(Food somefood) {
    health = somefood.healthgain;
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
