//
//  Agent.h
//  agent-simulator
//

#ifndef Agent_h
#define Agent_h
#include "Entity.hpp"
#include "Tile.h"
#include "Food.h"
#include <cstdlib>

class Board;

class Agent : public Entity {

public:
    // Initial Variables
    int health;    
    // Constructors
    Agent(Board& board);
    Agent(int innitHealth, int spawncoords[2], Board& board);
    
    // Actions
    void eat(Food someFood);
    bool age();
    void move(int direction[2]);
    int* randomMove(); // for returning coord array
    
    Agent& setAgentCoord(int coord[2]);
    
private:
    int numofPosMoves;
    std::vector<int> possibleMoves;
    //Board& internalBoard;
    std:: vector<Tile> lineOfSight; // internal "line of sight"
    void GenerateValidMoves(int viewRange);
    int viewRange;
    
    // Reference Coords
    const static int lookViewRefTable[9][2];

    // this is that direction reference dictionary we talked about that holds all the possible moves (ie (-1,1), (0,-1) etc) which can be iterated through and also multiplied by for  line of sight 
};


#endif /* Agent_h */
