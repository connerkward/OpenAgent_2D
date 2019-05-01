//
//  Food.h
//  agent-simulator
//
//  Created by Conner K Ward on 4/15/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Food_h
#define Food_h
#include "Entity.hpp"

class Food : public Entity {
public:
    Food();
    int healthgain;
    bool onFlag; // flagged if on Board
};

#endif /* Food_h */
