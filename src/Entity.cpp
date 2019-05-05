//
//  Entity.cpp
//  src
//
//  Created by Conner K Ward on 4/30/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(Environment& board) : internalBoard(board){
    entityChar = "-";
    int coord[] = {0,0};
    setCoord(coord);
    onFlag = false;
}


Entity& Entity::setCoord(int coord[2]){
    this->coord[0] = coord[0];
    this->coord[1] = coord[1];
    return *this;
}
