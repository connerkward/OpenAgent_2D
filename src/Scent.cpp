
//
//  Scent.cpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "Scent.hpp"
#include "Tile.h"
Scent::Scent(Environment& board) : Entity(board){
    entityChar = "-";
    distanceToFood = 1;
}
