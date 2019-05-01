#include "Board.h"
#include <iostream>
#include <chrono> // for timer
#include <thread> // for timer

// MAP
int LEGNTH = 30;
int WIDTH = 10;
int AGENTS = 1;
int FOODS = 1;
// SPAWN
int agent_spawn[2] =
{
    (LEGNTH)/2,
    (WIDTH)/2
};
// OTHER
int agent_health = 10;

// MAIN
int main(){
    Board board(LEGNTH,WIDTH,AGENTS,FOODS);
    board.spawnAgent(agent_spawn);
    board.print();
}
