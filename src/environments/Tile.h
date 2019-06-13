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
#include "../entities/Entity.hpp"

class Environment;

class Tile {
private:
    Entity* entity;

public:
	const int xPos;
	const int yPos;

    Tile(int x, int y);

    void placeEntity(Entity& newEntity);
    void removeEntity(); 
	ENTITY_TYPE getEntityType();

    friend std::ostream& operator<<(std::ostream& os, const Tile& thisTile);
    std::string tostring();

};

#endif /* Tile_h */
