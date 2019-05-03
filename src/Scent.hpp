//
//  Scent.hpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Scent_hpp
#define Scent_hpp
#include "Entity.hpp"
#include <stdio.h>
class Tile;
class Board;
class ScentFood;

class Scent : public Entity{
public:
    Scent(Environment& board, ScentFood& sf);
    ScentFood& theFood;
    int distanceToFood;
};

#endif /* Scent_hpp */
