//
//  Agent.h
//  agent-simulator
//

#ifndef Agent_h
#define Agent_h
#include "Food.h"
#include "Board.h"

class Agent {

public:
    int health;
    int playercord [2];
    Agent(int innitHealth, int spawn[2], Board& board); // b is reference to board object instatiated in main
    void eat(Food someFood);
    void move(int direction[2]);
    void randomMove();
    bool age();
private:
    Board& internalboard; // internal reference so we can check board state
};


#endif /* Agent_h */
