//
//  Environment.hpp
//  src
//
//  Created by Conner K Ward on 5/3/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

//I believe this class definition is correct but possibly not
#ifndef Environment_hpp
#define Environment_hpp

#include <stdio.h>
#include "Food.h"
#include "Agent.h"
#include "Obstacle.h"
#include "Tile.h"
#include <vector>
#include <string>
//Below #inlude added for fstream read from file functionality
#include <iostream>
#include <fstream>
#include <string>

class Environment;

template <class T>
std::vector<T> populate(int sizeOfPool, Environment& env, std::vector<T> entityPool) {
    entityPool.resize(sizeOfPool, T(env, 0, 0));
    return entityPool;
}

template <class T>
T& nextAvailableEntity(int entityCount, std::vector<T> &entityPool, Environment& env) {
    for (int i =0; i < entityCount; i++) {
        if (!entityPool[i].isOn()) {
            return entityPool[i];
        }
    }
    entityPool.push_back(T(env, 0, 0));
    return entityPool[entityCount + 1];
}

class Environment {
private:
	const int sizeX;
	const int sizeY;
	

	const int agentCount;
	int foodCount;
	int obstacleCount;
	const int tileCount;

	std::vector<std::vector<Tile>> tiles;
	std::vector<Agent> agents;
	std::vector<Food> foods;
	std::vector<Obstacle> obstacles;

	void createTiles();
	void createBorder();
    void TilesFromString(std::istringstream map);


public:
    Environment();
    Environment(int sizeX, int sizeY, int numAgents, int numFood);
    
    
    Tile& tile(int x, int y);
    
    bool step();

	bool checkForEndState();
	bool isValidLocation(int x, int y);

	std::vector<Tile> getView(int location[2], int radius);

	void moveAgent(Agent& agent, coord moveTo);
    
    void spawnAgent(int x, int y);
    void spawnObstacle(int x, int y);
	void spawnFood(int x, int y);

    Agent& findNextAgent();

    void print();
    std::string toString(); 
    void printUi();
};



/// ----CONNER COMMENT-------
// Everything in your code below is implementation, so should be in the .cpp file. You can make edits to main to test, just comment out what is already there. For example (pseudocode)
//main{
//    string filename = "map.txt";
//    Envinroment env(filename); // nick's alternate constructor
//    env.print(); // to check
//}
// If look above ^ inside this header file we are in, insert your constructor underneath
//     Environment();
//     Environment(int sizeX, int sizeY, int numAgents, int numFood);
//     here, line 68 or so

// besides some c++ specific syntax, which i dont fault you for, looks good
//// ----END CONNER COMMENT------


//while (k < 50) { // Con: is 50 an arbitrary test number of steps?
//    ifstream infile;
//    infile open("map" + std::to_string(k) + ".txt");
//
//    //k is number of map runs used, SHOULD BE ADJUSTED to desired number of runs
//    if (infile.fail()) {
//        cerr << "error opening map file" << end1;
//        exit(1);
//    }
//    k++;
//    // how does this reference external step functions? Is this appropriate place or should step function happen elsewhere in code?
//}
//
//using namespace std;
//
//// Function that return count of the given  
//// character in the string 
//
//int countEntity(string s, char c) // put this implementation inside environment.cpp
//    // header should include only
//    //int countEntity(string inputString, sometype typeofentity)
//{
//    // Count variable 
//    int res = 0;
//
//    for (int i = 0; i < s.length(); i++)
//
//        // checking character in string 
//        if (s[i] == c)
//            res++;
//
//    return res;
//}
//Driver code:
//string str = infile open("map" + std::to_string(k) + ".txt");
//char c = '@';
//cout << count(str, c) << endl;
//return 0;



	
#endif /* Environment_hpp */
