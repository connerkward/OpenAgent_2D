#include <iostream>
#include <chrono> // for timer
#include <thread> // for timer
#include "Environment.hpp"
#include "MapGenerator.hpp"

int LENGTH =20;
int WIDTH = 20;
int AGENTS = 2;
int FOODS = 4;
// SPAWN
int agent_spawn[2] =
{
    (WIDTH) / 2,
    (LENGTH) / 2
};

int agent_health = 40; // unused

// MAIN
int main() {
    MapGenerator mapgen;
    mapgen.generate();
    //myfile.open("map2.txt");

//    Environment board(LENGTH, WIDTH, AGENTS, FOODS);
//    board.spawnAgent(agent_spawn[0], agent_spawn[1]);
//
//    int vec[] = {4,4}; // arbitrary point
//    board.spawnAgent(vec[0], vec[1]);
//
//    int iters = 0;
//    //std::cout << board.print();
//    while (true) {
//        bool keepGoing = board.step();
//        if (!keepGoing) {
//            break;
//        }
//        std::cout << board.toString(); // added string return and kept direct board.print()
//
//        iters++;
//        //std::cout << "iterations:" << iters << std::endl;
//        std::this_thread::sleep_for (std::chrono::seconds(1));
//    }
}
