//
//  EntityManager.hpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef EntityManager_hpp
#define EntityManager_hpp
#include "Entity.hpp"
#include <stdio.h>
#include <vector>

class Board;

class EntityManager {
public:
    EntityManager(int n, Board &board);
    virtual Entity& spawn(int coords[2]);
    virtual void despawn(Entity& entity);
    virtual void populate(int n);
    int number;
    Board& internalBoard;
    std::vector<Entity> entities;
    //Entity& setCoords(int coords[2]);
    Entity& findAvail();
    bool onFlag;
    int* getCoord(Entity& entity);
    
};

#endif /* EntityManager_hpp */
