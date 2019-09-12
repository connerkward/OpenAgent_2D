//
//  Environment.hpp
//  src
//
//  Created by Conner K Ward on 5/3/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Environment_hpp
#define Environment_hpp

#include "../entities/Food.h"
#include "../entities/Obstacle.h"
#include "../entities/agents/Agent.h"
#include "Tile.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string> // For variable filename input to read map1.txt, map2.txt etc

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
	const int tileCount;
	const int agentCount;
	int foodCount;
	int obstacleCount;
	
	std::vector<std::vector<Tile>> tiles;
	std::vector<Agent> agents;
	std::vector<Food> foods;
	std::vector<Obstacle> obstacles;

	// Constructor utilities
	void createTiles();
	void createBorder();
    
	// General utilities
	int distance(const Tile& t1, const Tile& t2);
	bool checkForEndState();
	bool isValidLocation(int x, int y);

	// Printing utilities
	void tilesFromString(std::istringstream map);

public:
	const int sizeX;
	const int sizeY;

    Environment();
    Environment(int sizeX, int sizeY, int numAgents, int numFood);
    
    
    Tile& tile(int x, int y);
    
    bool step();

	

	std::vector<Tile> getView(Agent& agent, int radius);

	//void moveAgent(Agent& agent, coord moveTo);
    
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

using namespace std;

// Function that return count of the given  
// character in the string 
while (k < 50) { // Con: is 50 an arbitrary test number of steps?
	ifstream infile;
	infile open("map" + std::to_string(k) + ".txt");

	//k is number of map runs used, SHOULD BE ADJUSTED to desired number of runs
	if (infile.fail()) {
		cerr << "error opening map file" << end1;
		exit(1);
	}
	k++;
	// how does this reference external step functions? Is this appropriate place or should step function happen elsewhere in code?
}

using namespace std;

// Function that return count of the given  
// character in the string 

int countEntity(string s, char c) // put this implementation inside environment.cpp
    // header should include only
    //int countEntity(string inputString, sometype typeofentity)
{
	// Count variable 
	int res = 0;

	for (int i = 0; i < s.length(); i++)

		// checking character in string 
		if (s[i] == c)
			res++;

	return res;
}
//Driver code:
string str = infile open("map" + std::to_string(k) + ".txt");
char c = '@';
cout << count(str, c) << endl;
return 0;
>>>>>>> parent of c3f0f61... map generator update:src/Environment.hpp

int countEntity(string s, char c) // put this implementation inside environment.cpp
    // header should include only
    //int countEntity(string inputString, sometype typeofentity)
{
	// Count variable 
	int res = 0;

	for (int i = 0; i < s.length(); i++)

		// checking character in string 
		if (s[i] == c)
			res++;

	return res;
}


	
#endif /* Environment_hpp */
