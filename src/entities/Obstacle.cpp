//
//  Obstacle.h
//
//  Obstacle is an entity object that has an connected environement, and an internal set of coords.
//  The internal coords may be deprecated.
//
//  Created by Conner K Ward on 4/17/19.
//  Star Gods Dev Team
//

#include "Obstacle.h"
//#include "Board.h"

class Board;

Obstacle::Obstacle(Environment& board, int x = 0, int y = 0) : Entity(board, x, y) {
	entityType = OBSTACLE;
    entityChar = "*";
}
