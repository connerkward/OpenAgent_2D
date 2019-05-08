//
//  Obstacle.cpp
//  agent-simulator
//

///TODO Obstacle as Wall

#include "Obstacle.h"
//#include "Board.h"

class Board;

Obstacle::Obstacle(Environment& board, int x = 0, int y = 0) : Entity(board, x, y) {
	entityType = OBSTACLE;
    entityChar = "*";
}
