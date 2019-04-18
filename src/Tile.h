//
//  Tile.h
//  src
//
//  Created by Conner K Ward on 4/17/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//
#include "Food.h"
#include "Agent.h"
#ifndef Tile_h
#define Tile_h
#include <iostream>
class Tile{
private:
    Food food;
    Agent agent;
    int Tilex, Tiley;
public:
    /// Constructs a Hex
    Tile(int coord[2], Agent a, Food f);
    /// Sets the coordinates of the Hex
    void setCoords(int coord[2]);
    /// Checks if the Hex contains an Agent
    bool containsAgent();
    /// Checks if the Hex contains Food
    bool containsFood();
    friend std::ostream& operator<<(std::ostream& os, const Tile& t);
};
#endif /* Tile_h */
