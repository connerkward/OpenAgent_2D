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
#include <sstring> // For variable filename input to read map1.txt, map2.txt etc

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


//  ifstrean infile;
//  infile open (filename.txt)
// // this was written in main in the online example

//  while(k<50){
//  ifstream myfile("file_no_" + std::to_string(k) + ".vtk");
//  // myfile << "data to write\n";
//  k++;
//  }


//below lines written by hacking together the above two comment blocks

while (k < 50) {
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

int count(string s, char c)
{
	// Count variable 
	int res = 0;

	for (int i = 0; i < s.length(); i++)

		// checking character in string 
		if (s[i] == c)
			res++;

	return res;
}
Driver code: 
string str = infile open("map" + std::to_string(k) + ".txt");
char c = '@';
cout << count(str, c) << endl;
return 0;



	
#endif /* Environment_hpp */
