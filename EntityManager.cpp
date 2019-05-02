//
//  EntityManager.cpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "EntityManager.hpp"

EntityManager::EntityManager(int n , Board& board): internalBoard(board), number(n)
{
    populate(n);
}

// PRIVATE HELPERS
void EntityManager::populate(int n){
    Entity emptyEntity(internalBoard); // pointer to this instanc of Board
    entities.resize(n, emptyEntity);
}

Entity& EntityManager::findAvail(){
    // iterate through internal agents vector till one finds an avail agent
    for (int i =0; i < number; i++){
        if (!entities[i].onFlag){
            entities[i].onFlag = true;
            return entities[i];
        }
    }
    return entities[0];
}

Entity& EntityManager::spawn(int coords[2]){
    Entity& entity = findAvail();
    entity.setCoord(coords);
    return entity;
}

void EntityManager::despawn(Entity& entity){
    entity.onFlag = false;
}

int* EntityManager::getCoord(Entity& entity){
    return entity.coord;
}
