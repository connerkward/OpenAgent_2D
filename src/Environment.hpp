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
#include <string>

class Environment;

template <class T>
std::vector<T> populate(int sizeOfPool, Environment& env, std::vector<T> entityPool) {
    entityPool.resize(sizeOfPool, T(env, 0, 0));
    return entityPool;
}

template <class T>
T& nextAvailableEntity(int entityCount, std::vector<T> &entityPool, Environment& env) {
    for (int i =0; i < entityCount; i++) {
        if (!entityPool[i].isOn()) {
            return entityPool[i];
        }
    }
    entityPool.push_back(T(env, 0, 0));
    return entityPool[entityCount + 1];
}

class Environment {
private:
	const int sizeX;
	const int sizeY;

	const int agentCount;
	int foodCount;
	int obstacleCount;
	const int tileCount;

	std::vector<std::vector<Tile>> tiles;
	std::vector<Agent> agents;
	std::vector<Food> foods;
	std::vector<Obstacle> obstacles;

	void createTiles();
	void createBorder();

public:
    Environment(int sizeX, int sizeY, int numAgents, int numFood);
    
    Tile& tile(int x, int y);
    
    bool step();

	bool checkForEndState();
	bool isValidLocation(int x, int y);

	std::vector<Tile> getView(int location[2], int radius);

	void moveAgent(Agent& agent, coord moveTo);
    
    void spawnAgent(int x, int y);
    void spawnObstacle(int x, int y);
	void spawnFood(int x, int y);

    Agent& findNextAgent();

    void print();
    std::string toString();
    void printUi();
};

#endif /* Environment_hpp */
