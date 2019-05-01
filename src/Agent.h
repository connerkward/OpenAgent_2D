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
    int playercord [2];
    Agent(Board& board);
    Agent(int innitHealth, int spawncoords[2], Board &board);
    void eat(Food someFood);
    void move(int direction[2]); // may return a struct that contain a move
    void randomMove(); // may return a struct that contain a move
    bool age();
private:
    void populateLos(int viewRange);
    Board &internalboard;
    Tile lineOfSight[9]; // internal "line of sight"
    // need some way to package the internal board state
    const static int lookViewRefTable[9][2];
};


#endif /* Agent_h */
