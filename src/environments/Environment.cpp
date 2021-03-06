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
<<<<<<< HEAD:src/environments/Environment.cpp
<<<<<<< HEAD:src/environments/Environment.cpp
=======
void Environment::TilesFromString(std::istringstream map){
    std::string line;
    while(std::getline(map, line)){
        int strLength = line.length();
        for (int i=0; i>strLength; i++) {
            std::cout << line[i];
        }
    }
}
>>>>>>> parent of c3f0f61... map generator update:src/Environment.cpp
=======
>>>>>>> parent of bcfc133... from:src/Environment.cpp
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

bool Environment::step() {
	if (checkForEndState() == true) {
		for (int i = 0; i < agentCount; i++) {
			if (agents[i].isOn()) {

				moveAgent(agents[i], agents[i].step());
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

int distance(const Tile& t1, const Tile& t2) {
	return abs(t1.xPos - t2.xPos) + abs(t1.yPos - t2.yPos);
}

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

Tile& Environment::tile(int x, int y){
    Tile& ptr = tiles[y][x];
    return ptr;
}

void Environment::spawnAgent(int x, int y) {
    Agent& newAgent = nextAvailableEntity(agentCount, agents, *this);
	newAgent.xLoc = x , newAgent.yLoc = y;
	newAgent.changeState();
    tile(x, y).placeEntity(newAgent);
}

std::vector<Tile> getView(Agent& agent, int radius) {
	
}

void Environment::spawnFood(int x, int y) {
    Food& newFood = nextAvailableEntity(foodCount, foods, *this);
	newFood.xLoc = x , newFood.yLoc = y;
	newFood.changeState();
    tile(x, y).placeEntity(newFood);
}

void Environment::spawnObstacle(int x, int y) {
    Obstacle& newObstacle = nextAvailableEntity(obstacleCount, obstacles, *this);
	newObstacle.xLoc = x , newObstacle.yLoc = y;
	newObstacle.changeState();
    tile(x, y).placeEntity(newObstacle);
}

/// SETTERS
void Environment::moveAgent(Agent& agent, coord moveTo) {
//    std::cout << "from" << agent.xLoc << agent.yLoc << std::endl; // save for debug
//    std::cout << "to" << moveTo.x << moveTo.y << std::endl;
    tiles[agent.xLoc][agent.yLoc].removeEntity();
	agent.xLoc = moveTo.x , agent.yLoc = moveTo.y;
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
