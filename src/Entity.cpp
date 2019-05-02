//
//  Entity.cpp
//  src
//
//  Created by Conner K Ward on 4/30/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "Entity.hpp"
#include "Board.h"

Entity::Entity(Board& board) : internalBoard(board){
    entityChar = "-";
}


Entity& Entity::setCoord(int coord[2]){
    this->coord[0] = coord[0];
    this->coord[1] = coord[1];
    return *this;
}
