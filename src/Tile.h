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
#include "thing.hpp"
class Tile{
private:
    //Food food;
    //Agent agent;
    int Tilex, Tiley;
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
    friend std::ostream& operator<<(std::ostream& os, const Tile& t);
    std::string tileChar;
    //std::vector<thing> objects_on_Tile;

};
#endif /* Tile_h */
