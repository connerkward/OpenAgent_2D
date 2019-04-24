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
    int Tilex, Tiley; // coords
    void *Tile_ptr; // pointer to whatever object is "inside" the Tile
    
    bool containsFoodBool;
    bool containsAgentBool;
    bool containsObstacleBool;
    // ^ could either have a bunch of bool flags
    // with some logic that makes sure only bool can be true at once
public:
    /// Constructs a Hex
    //Tile(int coord[2], Agent a, Food f);
    Tile();
    Tile(int coord[2]);
    /// Sets the coordinates of the Hex
    void setCoords(int coord[2]);
    /// Checks if the Hex contains an Agent
    bool containsAgent();
    /// Checks if the Hex contains Food
    bool containsFood();
    /// Checks if the Hex contains Food
    bool containsObstacle();
    
    friend std::ostream& operator<<(std::ostream& os, const Tile& t); // honestly I couldnt tell you how friend works, but it allows Board to simple call cout << Tile

    std::string tileChar; // string containing the single char that gets printed by Board
};
#endif /* Tile_h */
