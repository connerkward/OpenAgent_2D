#include "Agent.h"
#include "Board.h"
#include <iostream>
#include <chrono> // for timer
#include <thread> // for timer

// map sizes
const int LEGNTH = 10;
const int WIDTH = 30;
// spawn is set to middle of level
int spawn[2] =
{
    (LEGNTH)/2,
    (WIDTH)/2
};
int health = 10;

int main(){
    
    
    Board myboard(LEGNTH,WIDTH);
    Agent agent(health, spawn, myboard);
    
    
    for(int i=0; i < 10; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        agent.age();
        std::cout << agent.health;
    }

    
    
    std::cout << "done" << "\n";
}
