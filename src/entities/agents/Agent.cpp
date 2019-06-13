#include "Agent.h"
#include <cstdlib>

using namespace std;

Agent::Agent(Environment& board, int x = 0, int y = 0) : boardRef(board), Entity(board, x, y) {
	entityChar = "@";
	entityType = AGENT;

    health = 10;
    viewRange = 1;
    numofPosMoves = 0;
    setGoalLoc(0, 0);
    onPath = false;
}
// INTERNAL HELPERS
// Find Valid Moves ---------
// *************To be Deprecated ******************
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
// *******************************


// PRIVATE HELPERS
void Agent::setGoalLoc(int x, int y){
    goalLoc.x = x;
    goalLoc.y = y;
}
bool Agent::setPath(std::stack<coord> aPath){
    myPath = aPath;
    return true;
}

/// PATHFINDING and LOS
// Find a path and return it as a stack of moves ie {(-1,1),(0,1),(1,1)....}
std::stack<coord> Agent::pathFind(){
    // search line of sight data structure,
        //sort paths by value and heuristic
        //sort paths by value and heuristic
    std::stack<coord> aPath;
    // populate aPath with best path
    return aPath;
}
bool Agent::genLineOfSight(){
    // bresanham raycast
    // for elements in ray array
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            internalView[i][j].x = i; // update internal view
            internalView[i][j].y = j; // update internal view
            internalView[i][j].tileRef = boardRef.tile(i, j); //hold reference to tile
        }
    }
    // returns a boolean if a goal is in sight
    return true;
}

/// MOVES
// Step
coord Agent::step(){ /// will be the only function that environment calls, will age, (env will still check for death and end of environment step)
    // radius 1 check, go for food
    if (onPath == true){ // if on a path
        return moveTowardsGoal();
    }
    else { // no path
        if (genLineOfSight() == false){ // gen LOS, no foods in sight
            return randomMove();
        }
        else { // foods in sight
            setPath(pathFind()); // a stack of moves (a path), set current path to it
            onPath = true;
            return moveTowardsGoal();
        }
    }
}

// MOVE TOWARDS LOCATION
coord Agent::moveTowardsGoal(){ // assumes there is a goal
    coord returnCoord = myPath.top();
    myPath.pop();
    return returnCoord;
}
// RANDOM MOVE IN ONE RADUS
// to be deprecated
coord Agent::randomMove() {
    // generate a valid random move based off of the line of sight, populates numofPosMove
    GenerateValidMoves(viewRange); // will eventually be replaced by LOS *****************
    // create default move at  0,0;
    coord thisCoord;
    thisCoord.x = 0;
    thisCoord.y = 0;
    if (numofPosMoves < 1) {
        // return 0,0 move
        return thisCoord;
    }
    else {
        // return random move from 9 possible moves
        thisCoord.x = xLoc + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][0];
        thisCoord.y = yLoc + lookViewRefTable[possibleMoves[(rand() % numofPosMoves)]][1];
        return thisCoord;
    }
}

/// EAT
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
