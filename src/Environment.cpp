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
    Agent emptyT(*this); // pointer to this instanc of Board
    agents.resize(agentCount, emptyT);
    Food emptyf(*this); // pointer to this instanc of Board
    foods.resize(foodCount, emptyf);
    Obstacle emptyO(*this); // pointer to this instanc of Board
    obstacles.resize(obstacleCount, emptyO);
    Tile emptyTile(*this);
    tiles.resize(sizeY, std::vector<Tile>(sizeX, emptyTile));
    fillEdgeTiles();
    
}

// HELPERS
void Environment::populateTiles(){

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
    tiles[agent.coord[0]][agent.coord[1]].clearPointer();
//    std::cout << "moevd from " << agent.coord[0] << agent.coord[1] << std::endl;
    agent.setCoord(coords);
    tiles[coords[0]][coords[1]].updatePointerWith(agent);
//    std::cout << "moevd to" << coords[0] << coords[1] << std::endl;

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
