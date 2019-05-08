#include "Agent.h"
#include <cstdlib>
#include "Environment.hpp"
using namespace std;

const int Agent::lookViewRefTable[9][2] =  {{-1,-1,},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};

Agent::Agent(Environment& board, int x = 0, int y = 0) : Entity(board, x, y) {
	entityChar = "@";
	entityType = AGENT;

    health = 10;
    viewRange = 1;
    numofPosMoves = 0;
}

// INTERNAL HELPERS
// Find Valid Moves
void Agent::GenerateValidMoves(int viewRange) {
    numofPosMoves = 0;
    this->possibleMoves.clear();
	int x, y;
    for (int curRange = 1; curRange <= viewRange; curRange++) {
        for (int i = 0; i < 9; i++){
            x = xLoc + lookViewRefTable[i][0] * curRange;
            y = yLoc + lookViewRefTable[i][1] * curRange;
			if (!viewOfEnvironment.isValidLocation(x, y)) {
				continue;
			}
            if (viewOfEnvironment.tile(x, y).occupied()) {
                if (viewOfEnvironment.tile(x, y).containsEntity(FOOD)) {    
                    possibleMoves.clear();
                    possibleMoves.push_back(i);
                    numofPosMoves++;
                    break;
                }
            }
            else {
                possibleMoves.push_back(i);
                numofPosMoves++;
            }
        }
    }
}

/// MOVE
/// RANDOM MOVE
int* Agent::randomMove() {
    // generate a valid random move based off of the line of sight
    GenerateValidMoves(viewRange);
    // create default move at  0,0;
    static int thismove[2] = {0,0};
    if (numofPosMoves < 1) {
        return thismove;
    }
    else {
        thismove[0] = xLoc + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][0];
        thismove[1] = yLoc + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][1];
        return thismove;
    }
}

void Agent::eat(Food food) {
    health = food.healthgain;
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
