//
//  Obstacle.h
//  src
//
//  Created by Conner K Ward on 4/17/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Obstacle_h
#define Obstacle_h
#include "Entity.hpp"

class Obstacle: public Entity {
public:
    Obstacle(Environment& board, int x, int y);
};

#endif /* Obstacle_h */
