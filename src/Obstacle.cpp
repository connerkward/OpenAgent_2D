//
//  Obstacle.cpp
//  agent-simulator
//

///TODO Obstacle as Wall

#include "Obstacle.h"
//#include "Board.h"

class Board;

Obstacle::Obstacle(Board& board) : Entity(board){
    entityChar = "*";
}
