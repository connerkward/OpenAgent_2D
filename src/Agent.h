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
private:
	int numofPosMoves;
	std::vector<int> possibleMoves;
	void GenerateValidMoves(int viewRange);
	int viewRange;

	// Reference Coords
	const static int lookViewRefTable[9][2];
public:
    int health;    

    Agent(Environment& board, int x, int y);   

    void eat(Food someFood);
    bool age();
    int* move();
    int* randomMove();
};

#endif /* Agent_h */
