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
    Agent(Environment& board);    
    // Actions
    void eat(Food someFood);
    bool age();
    int* move();
    int* randomMove();
    
private:
    int numofPosMoves;
    std::vector<int> possibleMoves;
    std:: vector<Tile> lineOfSight;
    void GenerateValidMoves(int viewRange);
    int viewRange;
    
    // Reference Coords
    const static int lookViewRefTable[9][2];
};


#endif /* Agent_h */
