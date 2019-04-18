#include "Agent.h"
#include "Board.h"
#include "Food.h"
#include <iostream>
#include <chrono> // for timer
#include <thread> // for timer

// MAP
int LEGNTH = 10;
int WIDTH = 10;
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
    
    Board myboard(LEGNTH,WIDTH);
    Agent agent(agent_health, agent_spawn, myboard);
    Food food;
    
    myboard.spawnAgent(agent, agent_spawn);
    
    int steps = 0;
    bool playing = true;
    while(playing == true){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        for(int i=0; i < LEGNTH; i++){
            for(int j=0; j < WIDTH; j++){
                std::cout << myboard.grid[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << steps << std::endl;
        agent.randomMove();
        steps++;
    }


    // Testing Agent Life Drain
//    for(int i=0; i < 10; i++){
//        std::this_thread::sleep_for(std::chrono::milliseconds(500));
//        agent.age();
//        if (agent.health <= 0){
//            std::cout << "dead!" << "\n";
//            break;
//        }
//        std::cout << agent.health;
//    }
}
