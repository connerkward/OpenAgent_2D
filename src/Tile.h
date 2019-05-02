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

class Tile: public Entity {
private:
    int Tilex;
    int Tiley;
    void setCoords(int coord[2]);
    Entity* ent; // the magical pointer to everything except my sanity

public:
    Tile();
    Tile(int coord[2]);
    void updatePointerWith(Entity& entToMove); // update pointer (ent) with reference to entity which is to be moved
    void clearPointer(); // update pointer (ent) with reference to entity which is to be moved
    bool containsSomething();
    bool containsObstacle;


    void removePointer();
    //bool containsAgent();
	//bool containsFood();
    //bool containsObstacle();

	//bool giveFood(Food& food);
	//bool giveAgent(Agent& agent);


	//bool operator==(const Tile& otherTile);
	//bool operator!=(const Tile& otherTile);
    
    friend std::ostream& operator<<(std::ostream& os, const Tile& thisTile); // honestly I couldnt tell you how friend works, but it allows Board to simple call cout << Tile
};

#endif /* Tile_h */
