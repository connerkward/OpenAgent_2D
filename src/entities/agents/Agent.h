//
//  Agent.h
//  agent-simulator
//

#ifndef Agent_h
#define Agent_h

#include "../Entity.hpp"
#include "../Food.h"
#include "agent_utils/AgentEnvView.h"
#include "../../environments/Tile.h"
#include <cstdlib>
#include <stack>

class Environment;
class Tile;

class Agent : public Entity {
private:
	int health;
	int x_pos, y_pos;
	AgentEnvView envView;
    
	

public:
    
	Agent(int sizeX, int sizeY, int init_x = 0, int init_y = 0, int init_health = 10);
    void eat(Food someFood);
    bool age();    

	// TODO: Add method for updating envView

	// TODO: Add method for searching envView for a target

	// TODO: Add method for querying Agent for an Action to return

	// TODO: Add function to reset Agent health to some default value
};

#endif /* Agent_h */
