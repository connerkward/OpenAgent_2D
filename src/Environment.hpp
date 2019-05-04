//
//  Environment.hpp
//  src
//
//  Created by Conner K Ward on 5/3/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Environment_hpp
#define Environment_hpp

#include <stdio.h>
#include "Food.h"
#include "Agent.h"
#include "Obstacle.h"
#include "Tile.h"
#include <vector>


class Environment; // forward declare

// -----------------------TEMPLATES------------------------------
// Template Functions for manipulating vectors
// Populate an pool
template <class T>
void populate(int n, Environment& env, std::vector<T> pool){
    T emptyT(env); // pointer to this instance of Board
    emptyT.onFlag = true;
    pool.resize(n, emptyT);
}

template <class T>
T& findAvailinPool(int sizeOfPool, std::vector<T> &pool){
    // iterate through internal agents vector till one finds an avail agent
    for (int i =0; i < sizeOfPool; i++){
        if (!pool[i].onFlag){
            pool[i].onFlag = true;
            return pool[i];
        }
    }
    return pool[0];
}

// --------------------------------CLASS------------------------------
class Environment{
public:
    // Constructors
    // Obstacle and Tile counts auto generated
    Environment();
    Environment(int sizeX, int sizeY, int aCount, int fCount);
    
    // Tile Management
    Tile& getTileAt(int coords[2]);
    std::vector<std::vector<Tile>> tiles;

    
    //Step
    void step(int = 1); // not yet working, add default as 1 unless user enters parameter
    void moveAgent(Agent& agent, int coords[2]);
    
    // Spawners
    void spawnAgent(int coords[2]);
    void spawnObstacle(int coords[2]);
    void spawnFood(int coords[2]);
    void spawnTile(int coords[2]);
    
    // Printers
    void print();
    void printUi();
    
private:
    // Initial Board Parameters
    const int sizeX;
    const int sizeY;
    
    const int agentCount;
    int foodCount;
    int obstacleCount;
    const int tileCount;
    
    // Object Pools
    std::vector<Agent> agents;
    std::vector<Food> foods;
    std::vector<Obstacle> obstacles;
    
    
    // Helpers
    void populateTiles();
    void fillEdgeTiles(); // filles board edges with obstacles
};

#endif /* Environment_hpp */
