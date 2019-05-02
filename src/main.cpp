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
    (WIDTH)/2,
    (LEGNTH)/2
};
// OTHER
int agent_health = 10;

// MAIN
int main(){
    Board board(LEGNTH,WIDTH,AGENTS,FOODS);

    board.spawnAgent(agent_spawn);
    int vec[2] = {4,4}; // arbitrary point
    board.spawnFood(vec);

    board.print();
    //board.printUi();
    while(true){
        board.step(1);
        board.print();
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}
