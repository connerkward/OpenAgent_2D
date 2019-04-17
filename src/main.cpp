#include "Agent.h"
#include "Board.h"
#include "Food.h"
#include <iostream>
#include <chrono> // for timer
#include <thread> // for timer

// MAP
const int LEGNTH = 10;
const int WIDTH = 30;
// SPAWN
int spawn[2] =
{
    (LEGNTH)/2,
    (WIDTH)/2
};
// OTHER
int health = 10;

// MAIN
int main(){
    
    Board myboard(LEGNTH,WIDTH);
    Agent agent(health, spawn, myboard);
    Food food;
    
    for(int i=0; i < 10; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        agent.age();
        if (agent.health <= 0){
            std::cout << "dead!" << "\n";
            break;
        }
        std::cout << agent.health;
    }

    
    
    std::cout << "done" << "\n";
}
