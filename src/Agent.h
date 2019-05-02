//
//  Agent.h
//  agent-simulator
//

#ifndef Agent_h
#define Agent_h
#include "Entity.hpp"
#include "Tile.h"
#include "Food.h"

class Board;

class Agent : public Entity {

public:
    int health;
    int agentCoord [2];
    Agent(Board& board);
    Agent(int innitHealth, int spawncoords[2], Board &board);
    void eat(Food someFood);
    void move(int direction[2]);
    void randomMove();
    bool age();
    bool onFlag; // to flag if agent is active on board
    Agent& setCoord(int coord[2]);
    
private:
    void populateLos(int viewRange);
    Board &internalboard;
    Tile lineOfSight[9]; // internal "line of sight"
    const static int lookViewRefTable[9][2];
    // this is that direction reference dictionary we talked about that holds all the possible moves (ie (-1,1), (0,-1) etc) which can be iterated through and also multiplied by for  line of sight 
};


#endif /* Agent_h */
