/**
	A data structure representing the environment an Agent lives in.

	A Board is made up of Tiles, which can contain either Food or
	Agents or Obstacles.

*/
#include "Board.h"

// CONSTRUCTORS
// populate empty board
Board::Board(int x, int y, int acount, int fcount) : sizeX(x), sizeY(y), agentCount(acount), foodCount(fcount), obstacleCount(x*y)
{
    aCounter = 0;
    fCounter = 0;
    oCounter = 0;
    
    // Build Board
    populateObstacles();
    fillEmptyTiles();
    fillEdgeTiles();
    
    // Populate Other Entity Pools
    populateAgents();
    populateFoods();
}

// HELPERS
// Populators
void Board::populateObstacles(){
    const Obstacle emptyObstacle;
    obstacles.resize(sizeY*sizeX, emptyObstacle);
}
void Board::populateAgents(){
    Agent emptyAgent(*this); // pointer to this instanc of Board
    agents.resize(agentCount, emptyAgent);
}
void Board::populateFoods(){
    Food emptyFood;
    foods.resize(foodCount, emptyFood);
}

// populate board with empty tile instances
void Board::fillEmptyTiles(){
    Tile emptyTile;
    tiles.resize(sizeY, std::vector<Tile>(sizeX, emptyTile));
}

// populate border with obstacles from obstacle stack
void Board::fillEdgeTiles(){
    for(int i=0; i < sizeX; i++){
        for(int j=0; j < sizeY; j++){
            if(i == 0 || j == 0 || i == sizeY-1 || j == sizeX-1){
                int coords[2] = {i,j};
                spawnObstacle(coords);
            }
        }
    }
}

//SPAWNERS
void Board::spawnAgent(int coords[2]){
    tiles[coords[0]][coords[1]].updatePointerWith(&agents[aCounter]);
    aCounter ++;
}
void Board::spawnFood(int coords[2]){
    tiles[coords[0]][coords[1]].updatePointerWith(*foods[fCounter]);
    fCounter ++;
}
void Board::spawnObstacle(int coords[2]){
    tiles[coords[0]][coords[1]].updatePointerWith(*obstacles[oCounter]);
    oCounter ++;
}

// GETTERS
Tile Board::getTile(int coords[2]){
    return tiles[coords[0]][coords[1]];
}

// PRINTERS
void Board::print(){
    for(int i=0; i < sizeX; i++){
        for(int j=0; j < sizeY; j++){
            std::cout << tiles[i][j];
        }
        std::cout << std::endl;
    }
}

