//
//  Obstacle.h
//
//  Obstacle is an entity object that has an connected environement, and an internal set of coords.
//  The internal coords may be deprecated.
//
//  Created by Conner K Ward on 4/17/19.
//  Star Gods Dev Team
//

#ifndef Obstacle_h
#define Obstacle_h
#include "Entity.hpp"

class Obstacle: public Entity {
public:
    Obstacle(Environment& board, int x, int y);
};

#endif /* Obstacle_h */
