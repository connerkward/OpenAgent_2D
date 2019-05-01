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
    Obstacle emptyObstacle;
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
    //for(int i=0; i < sizeY; i++){
    //    for(int j=0; j < sizeX; j++){
            //std::cout << tiles[i][j];// debug
      //  }
        //std::cout << std::endl;// debug
    //}
}

// populate border with obstacles from obstacle stack
void Board::fillEdgeTiles(){
    for(int i=0; i < sizeY; i++){
        for(int j=0; j < sizeX; j++){
            if(i == 0 || j == 0 || i == sizeY-1 || j == sizeX-1){
                int coords[2] = {i,j};
                //std::cout << "COORDS" << coords[0]; // debug
                //std::cout << coords[1] << std::endl;// debug
                spawnObstacle(coords);
            }
        }
    }
}

//SPAWNERS
void Board::spawnAgent(int coords[2]){
    tiles[coords[0]][coords[1]].updatePointerWith(agents[aCounter]);
    //std::cout << "acounter:" << aCounter << std::endl;
    aCounter ++;
}
void Board::spawnFood(int coords[2]){
    tiles[coords[0]][coords[1]].updatePointerWith(foods[fCounter]);
    //std::cout << "fcounter:"  << fCounter<< std::endl;
    fCounter ++;
}
void Board::spawnObstacle(int coords[2]){
    tiles[coords[0]][coords[1]].updatePointerWith(obstacles[oCounter]);
    //std::cout << "ocounter:"  << oCounter<< std::endl;
    oCounter ++;
}

void Board::step(int steps = 1){ // not working
    for(int i=0; i <= steps; i++){
        for(int i=0; i < agentCount; i++){
            if (agents[i].onFlag){
                agents[i].randomMove();
            }
        }
    }
}

// GETTERS
Tile Board::getTile(int coords[2]){
    return tiles[coords[0]][coords[1]];
}

// PRINTERS
void Board::print(){
    for(int i=0; i < sizeY; i++){
        for(int j=0; j < sizeX; j++){
            std::cout << tiles[i][j];
        }
        std::cout << std::endl;
    }
}

void Board::printUi(){
    std::cout << "Agents: " << agentCount << " Foods: " << agentCount << std::endl;
    
    std::string s = "-";
    std::string s1 = s;
    for (int i=1; i<sizeX;i++)
        s += s1; // Concatinating strings
    
    std::cout << s << std:: endl;
    
}

