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
#include "AgentManager.hpp"
#include "agentMovePackage.hpp"
#include "FoodManager.hpp"

class Board {

private:
    // Initial Board Parameters
	const int sizeX;
	const int sizeY;
    const int foodCount;
    const int agentCount;
    const int obstacleCount; // is automatically determined as of now for edges
    
    // Object Pools
    AgentManager aManager;
    FoodManager fManager;
    std::vector<Obstacle> obstacles;
    // replace each entity type with managers such that
    // AgentManager<-GameManager->Board
    // ObstacleManager<-GameManager->FoodManager
    // where Board is essentially "TileManager"
    
    // Pool Iteration Helpers
    int oCounter; // this is whats happening

    // Object Pool for Tiles
    std::vector<std::vector<Tile>> tiles;
    
    // Helpers
    void fillEmptyTiles(); // fills board with empty tiles
    void fillEdgeTiles(); // filles board edges with obstacles
    void populateObstacles(); // populates the obstacle array
    void updateBoard(agentMovePackage movePackage);
    
//    // Removers
//    bool removeAgent(Tile& tile);
//    bool removeFood(Tile& tile);

public:
    // Constructors
	Board(); 
	//Board(int x, int y);
    Board(int x, int y, int acount, int fcount); //for setting agentcount and foodcount
    
    // Spawners
    void spawnAgent(int coords[2]);
    void spawnFood(int coords[2]);
    void spawnObstacle(int coords[2]);
    
    // Getters
    
    Tile& getTile(int coords[2]);
    
    //Step
    void step(int steps); // not yet working, add default as 1 unless user enters parameter
    void moveAgent(Agent& agent, int coords[2]);
    
    // Printers
    void print();
    void printUi();
    

    
//    Board(int sizeX, int sizeY, std::vector<int[2]> agentLocations,
//          std::vector<int[2]> foodLocations, std::vector<int[2]> obstacleLocations);
//
//    // Getters
//    Agent getAgent(int agentLabel);

//    bool moveAgent(int label, int dest[2]); 
};

#endif /* Board_h */
