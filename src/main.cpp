#include <iostream>
#include <chrono> // for timer
#include <thread> // for timer
#include "Environment.hpp"

// MAP
int LEGNTH = 20;
int WIDTH = 20;
int AGENTS = 1;
int FOODS = 4;
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
    Environment board(LEGNTH,WIDTH,AGENTS,FOODS);

    board.spawnAgent(agent_spawn);
    int vec[] = {4,4}; // arbitrary point
    board.spawnFood(vec);
    int vec2[] = {6,6}; // arbitrary point
    board.spawnFood(vec2);
    int vec3[] = {6,9}; // arbitrary point
    board.spawnFood(vec3);
    int vec4[] = {15,15}; // arbitrary point
    board.spawnObstacle(vec4);
    int vec5[] = {6,7}; // arbitrary point
    board.spawnObstacle(vec4);
    
    board.print();
    while(true){
        board.step(1);
        board.print();
        //std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}
