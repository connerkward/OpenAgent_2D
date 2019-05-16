//
//  Environment.cpp
//  src
//
//  Created by Conner K Ward on 5/3/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "Environment.hpp"

Environment::Environment(int sizeX, int sizeY, int aCount, int fCount):
    sizeX(sizeX),
    sizeY(sizeY),
    agentCount(aCount),
    foodCount(fCount),
    tileCount(sizeY*sizeX),
    obstacleCount(sizeY*sizeX)
{
    createTiles();
    obstacles = populate(obstacleCount, *this, obstacles);
    foods = populate(foodCount, *this, foods);
    agents = populate(agentCount, *this, agents);
	createBorder();
}

// INITIALIZERS
void Environment::createTiles() {
    tiles.reserve(sizeY);
	for (int i = 0; i < sizeY; i++) {
		tiles.push_back(std::vector<Tile>());
		tiles[i].reserve(sizeX);
		for (int j = 0; j < sizeX; j++) {
			tiles[i].push_back(Tile(j, i));
		}
	}
}

void Environment::createBorder() {
    for(int i=0; i < sizeY; i++){
        for(int j=0; j < sizeX; j++) {
            if(i == 0 || j == 0 || i == sizeY-1 || j == sizeX-1){
                spawnObstacle(j, i);
            }
        }
    }
}

/// STEPPER
bool Environment::step() {
	if (checkForEndState() == true) {
		for (int i = 0; i < agentCount; i++) {
			if (agents[i].isOn()) {

				moveAgent(agents[i], agents[i].randomMove());
				agents[i].age();
				if (agents[i].health == 0) {
					agents[i].changeState();
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}
/// CHECKERS
bool Environment::checkForEndState() {
	for (int i = 0; i < agentCount; i++) {
		if (agents[i].isOn()) {
			return true;
		}
	}
	return false;
}

bool Environment::isValidLocation(int x, int y) {
	if (x < 0 || y < 0 || x > sizeX || y > sizeY) {
		return false;
	}
	else {
		return true;
	}
}

/// GETTERS
Tile& Environment::tile(int x, int y){
    Tile& ptr = tiles[y][x];
    return ptr;
}

/// SPAWNERS
void Environment::spawnAgent(int x, int y) {
    Agent& newAgent = nextAvailableEntity(agentCount, agents, *this);
	newAgent.xLoc = x, newAgent.yLoc = y;
	newAgent.changeState();
    tile(x, y).placeEntity(newAgent);
}

void Environment::spawnFood(int x, int y) {
    Food& newFood = nextAvailableEntity(foodCount, foods, *this);
	newFood.xLoc = x, newFood.yLoc = y;
	newFood.changeState();
    tile(x, y).placeEntity(newFood);
}

void Environment::spawnObstacle(int x, int y) {
    Obstacle& newObstacle = nextAvailableEntity(obstacleCount, obstacles, *this);
	newObstacle.xLoc = x, newObstacle.yLoc = y;
	newObstacle.changeState();
    tile(x, y).placeEntity(newObstacle);
}

/// SETTERS
void Environment::moveAgent(Agent& agent, coord moveTo) {
//    std::cout << "from" << agent.xLoc << agent.yLoc << std::endl; // save for debug
//    std::cout << "to" << moveTo.x << moveTo.y << std::endl;
    tiles[agent.xLoc][agent.yLoc].removeEntity();
	agent.xLoc = moveTo.x, agent.yLoc = moveTo.y;
    tiles[moveTo.x][moveTo.y].placeEntity(agent);
}

///PRINTERS
std::string Environment::toString() {
    std::string returnstring;
    for(int i=0; i < sizeY; i++) {
        for (int j=0; j < sizeX; j++) {
            returnstring += tiles[i][j].tostring();
        }
        returnstring += "\n";
    }
    return returnstring;
}
    
void Environment::print() {
    for(int i=0; i < sizeY; i++) {
        for (int j=0; j < sizeX; j++) {
            std::cout << tile(i,j);
        }
        std::cout << std::endl;
    }
}
