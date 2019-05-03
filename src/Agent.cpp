#include "Agent.h"
#include <cstdlib>
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
    onFlag = true;
    coord[0] = 0;
    coord[1] = 0;
    entityChar = "@";
    viewRange = 1;
    numofPosMoves = 0;
}

// INTERNAL HELPERS
// Find Valid Moves
void Agent::GenerateValidMoves(int viewRange){
    numofPosMoves = 0;
    possibleMoves.clear();
    int lookCoord[2];
    for (int curRange = 0; curRange < viewRange; curRange++){
        for (int i = 0; i < 9; i++){
            lookCoord[0] = this->coord[0] + lookViewRefTable[i][0] * curRange;
            lookCoord[1] = this->coord[1] + lookViewRefTable[i][1] * curRange;
            //        std::cout << "tile contains " << internalBoard.getTile(lookCoord).containsSomething() << std::endl;
            if (internalBoard.getTile(lookCoord).containsSomething()){
                if (internalBoard.getTile(lookCoord).containsFood()){
                    possibleMoves.clear();
                    possibleMoves.push_back(i);
                    numofPosMoves++;
                    break;
                }
            }
            else{
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
    // create default move();
    static int thismove[2];
    thismove[0] = lookViewRefTable[5][0];
    thismove[1] = lookViewRefTable[5][1];
    if (numofPosMoves < 1){
        std::cout << "stuck, none possible";
        return thismove;
    }
    else{
        thismove[0] = coord[0] + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][0];
        thismove[1] = coord[1] + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][1];
        std::cout << numofPosMoves << thismove[0] << thismove[1] << endl;
        return thismove;
    }
}

/// EAT
void Agent::eat(Food somefood) {
    /// EatinternalBoard grant health proportional to value of Food
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
