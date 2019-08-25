#include <iostream>
#include <chrono> // for timer
#include <thread> // for timer
#include "Environment.hpp"
#include "MapGenerator.hpp"

// CONSTANTS (to be defaulted unless user input)
int LENGTH =20;
int WIDTH = 20;
int AGENTS = 2;
int FOODS = 4;

// MAIN
int main() {
<<<<<<< HEAD
    
    /// FLOW
    // GET USER INPUT (If any)
    // GENERATE MAP FROM PARAMETERS
    // CREATE ENVIRONMENT OBJECT FROM MAP
    // STEP ENVIRONMENT (Until Stop-Flag is raised)
}























/// --------Everything left below is only for reference-------

// SPAWN LOCATION (to be deprecated)
//int agent_spawn[2] =
//{
//    (WIDTH) / 2,
//    (LENGTH) / 2
//};
//
//// only for debuging purposes, (to be deprecated)
//int agent_health = 40; // unused

//    MapGenerator mapgen;
//    for (int i =0; i < 10; i++){
//        std::string str = "map" + std::to_string(i) + ".txt";
//        std::cout << mapgen.generate(str) << std::endl;
//    }
//myfile.open("map2.txt");
=======
    MapGenerator mapgen;
    mapgen.generate();
    //myfile.open("map2.txt");
>>>>>>> parent of c3f0f61... map generator update

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
