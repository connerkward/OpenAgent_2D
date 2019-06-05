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
#include <stack>

struct coord{
    int x;
    int y;
};

struct ViewTile{
    int x;
    int y;
    bool beenVisited;
    
    
};

class Board;

class Agent : public Entity {
private:
    const static int lookViewRefTable[9][2];

    coord randomMove();
    coord moveTowardsGoal();
    
    void setGoalLoc( int x, int y); // hypocrite i am
    coord goalLoc; // stores location of goal
    
    
    int numofPosMoves;
    std::vector<int> possibleMoves;
    void GenerateValidMoves(int viewRange);
    int viewRange;
    
    bool onPath;
    bool setPath(std::stack<coord> aPath); // like i said, hypocrite
    std::stack<coord> myPath;
    
    std::vector<std::vector<ViewTile>> internalView;
    
    std::stack<coord> pathFind();
    bool genLineOfSight(); /// on you buddy boy
    std::vector<coord> lineOfSight;
    

public:
    int health;
    Agent(Environment& board, int x, int y);
    void eat(Food someFood);
    bool age();
    coord step();
    
};

#endif /* Agent_h */
