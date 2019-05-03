//
//  Environment.cpp
//  src
//
//  Created by Conner K Ward on 5/3/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "Environment.hpp"

Environment::Environment(int sizeX, int sizeY, int agentCount, int foodCount):
    sizeX(sizeX),
    sizeY(sizeY),
    agentCount(agentCount),
    foodCount(foodCount),
    tileCount(sizeY*sizeX)
{
    populate(agentCount, *this, agents);
    populate(foodCount, *this, foods);
    populate(obstacleCount, *this, obstacles);
    populateTiles();
    
}

// HELPERS
void Environment::populateTiles(){
    Tile emptyTile(*this);
    tiles.resize(sizeY, std::vector<Tile>(sizeX, emptyTile));
}

void Environment::fillEdgeTiles(){
    for(int i=0; i < sizeY; i++){
        for(int j=0; j < sizeX; j++){
            if(i == 0 || j == 0 || i == sizeY-1 || j == sizeX-1){
                int coords[] = {i,j};
                spawnObstacle(coords);
            }
        }
    }
}

void Environment::step(int steps){
    for(int i =0; i < agentCount; i++){
        if (agents[i].onFlag){
            moveAgent(agents[i], agents[i].randomMove());
            
        }
    }
}

// GETTERS
Tile& Environment::getTileAt(int coords[2]){
    Tile& ptr = tiles[coords[0]][coords[1]];
    return ptr;
}

/// SETTERS
// SPAWNERS
void Environment::spawnAgent(int coords[2]){
    Agent& a = findAvailinPool(agentCount, agents);
    a.setCoord(coords);
    tiles[coords[0]][coords[1]].updatePointerWith(a);
}
void Environment::spawnFood(int coords[2]){
    Food& f = findAvailinPool(foodCount, foods);
    f.setCoord(coords);
    tiles[coords[0]][coords[1]].updatePointerWith(f);
}
void Environment::spawnObstacle(int coords[2]){
    Obstacle& o = findAvailinPool(obstacleCount, obstacles);
    o.setCoord(coords);
    tiles[coords[0]][coords[1]].updatePointerWith(o);
}
// SET AGENT POSITION
void Environment::moveAgent(Agent& agent, int coords[2]){
    tiles[agent.coord[0]][agent.coord[0]].clearPointer();
    tiles[coords[0]][coords[1]].updatePointerWith(agent);
}

/// PRINTERS
void Environment::print(){
    for(int i=0; i < sizeY; i++){
        for(int j=0; j < sizeX; j++){
            std::cout << tiles[i][j];
        }
        std::cout << std::endl;
    }
}
