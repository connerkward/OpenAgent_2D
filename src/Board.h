//
//  Board.h
//  agent-simulator
//
//  Created by Conner K Ward on 4/15/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include <string>
#include <vector>
#include "Tile.h"
//#include "Agent.h"
class Agent;

class Board {

private:
	const int DEFAULTSIZE = 12; // default for grid, not necessary
	int sizeX;
	int sizeY;
	vector<Agent> agents;
	vector<vector<Tile>> tiles;

	// Removers
	bool removeAgent(int label);
	bool removeFood(Tile& tile);

public:
	// Constructors
	Board(); 
	Board(int sizeX, int sizeY); 
	Board(int sizeX, int sizeY, vector<int[2]> agentLocations,
		vector<int[2]> foodLocations, vector<int[2]> obstacleLocations);

	// Getters
	Tile getTile(int x, int y);
	Agent getAgent(int agentLabel);

	// Setters
	bool placeAgent(int x, int y, Agent &agent);
	bool placeObstacle(int x, int y, Obstacle &obstacle);
	bool placeFood(int x, int y, Food &food);

	bool moveAgent(int label, int dest[2]);

};

#endif /* Board_h */
