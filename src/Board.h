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
#include <iostream>
#include <vector>
#include "Food.h"
#include "Tile.h"
#include "Obstacle.h"

#include "Agent.h"
//class Agent;

class Board {

private:
    friend class Agent;
    
    // Initial Board Parameters
	const int sizeX;
	const int sizeY;
    const int foodCount;
    const int agentCount;
    const int obstacleCount;
    
    // Object Pools
    std::vector<Agent> agents;
    std::vector<Food> foods;
    std::vector<Obstacle> obstacles;
    // Pool Iteration Helpers
    int fCounter;
    int aCounter;
    int oCounter;

    // Object Pool for Tiles
    std::vector<std::vector<Tile>> tiles;
    
    // Helpers
    void fillEmptyTiles();
    void fillEdgeTiles();
    void populateFoods();
    void populateAgents();
    void populateObstacles();
    
//    // Removers
//    bool removeAgent(Tile& tile);
//    bool removeFood(Tile& tile);

public:
	// Constructors
	Board(); 
	Board(int x, int y);
    Board(int x, int y, int acount, int fcount);
    
    // Spawners
    void spawnAgent(int coords[2]);
    void spawnFood(int coords[2]);
    void spawnObstacle(int coords[2]);
    
    // Printers
    void print();
    
    // Getters
    Tile getTile(int coords[2]);
    

    
//    Board(int sizeX, int sizeY, std::vector<int[2]> agentLocations,
//          std::vector<int[2]> foodLocations, std::vector<int[2]> obstacleLocations);
//
//    // Getters
//    Agent getAgent(int agentLabel);
//
//    // Setters
//    bool placeAgent(int x, int y, Agent &agent);
//    bool placeObstacle(int x, int y, Obstacle &obstacle);
//    bool placeFood(int x, int y, Food &food);
//
//    bool moveAgent(int label, int dest[2]);
};

#endif /* Board_h */
