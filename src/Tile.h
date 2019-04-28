//
//  Tile.h
//  src
//
//  Created by Conner K Ward on 4/17/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Tile_h

#define Tile_h

#include <iostream>
#include <string>
#include <vector>

class Tile{
private:
    
	Tile(int x, int y);

	int x, int y;
	Agent* agent;
	Food* food;
	bool isObstacle;

	static vector<Tile> tiles;

public:
    
	Tile tile(int x, int y);

    bool containsAgent();
	bool containsFood();
    bool containsObstacle();

	bool giveFood(Food& food);
	bool giveAgent(Agent& agent);

	bool removeFood();
	bool removeAgent();

	bool operator==(const Tile& otherTile);
	bool operator!=(const Tile& otherTile);
    
    friend std::ostream& operator<<(std::ostream& os, const Tile& t); // honestly I couldnt tell you how friend works, but it allows Board to simple call cout << Tile

    std::string tileChar; // string containing the single char that gets printed by Board
};

#endif /* Tile_h */
