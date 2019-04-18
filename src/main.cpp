#include "Agent.h"
#include "Board.h"
#include "Food.h"
#include <iostream>
#include <chrono> // for timer
#include <thread> // for timer
using namespace std;

// MAP
int LEGNTH = 5;
int WIDTH = 8;
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
    
    for(int i=0; i < LEGNTH; i++){
        for(int j=0; j < WIDTH; j++){
            cout << myboard.grid[i][j];
        }
        cout << endl;
    }
    
    myboard.spawnAgent(agent, agent_spawn)

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
