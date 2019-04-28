//
//  Agent.h
//  agent-simulator
//

#ifndef Agent_h
#define Agent_h
#include "Food.h"
#include "Board.h"
class Board;

class Agent {

public:
    int health;
    int playercord [2];
    Agent();
    Agent(int innitHealth, int spawncoords[2], Board &board); // does agent need board refernce?
    void eat(Food someFood);
    void move(int direction[2]);
    void randomMove();
    bool age();
private:
    Tile internalboard[9]; // internal "line of sight"
    // need some way to package the internal board state
    
};


#endif /* Agent_h */
