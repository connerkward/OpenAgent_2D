//
//  Tile.h
//  src
//
//  Created by Conner K Ward on 4/17/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Tile_h

#define Tile_h

#include <iostream>
#include <string>
#include <vector>
#include "Entity.hpp"

class Environment;

class Tile {
private:
    Entity* entityWithin;
	int coordinates[2];

public:
    Tile(int x, int y);

    bool placeEntity(Entity &entity);
    bool removeEntity(); 

    bool occupied();
	bool containsEntity(ENTITY_TYPE entityType);

    friend std::ostream& operator<<(std::ostream& os, const Tile& thisTile);
};

#endif /* Tile_h */
