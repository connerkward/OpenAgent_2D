//
//  Tile.h
//  src
//
//  Created by Conner K Ward on 4/17/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Tile_h
#define Tile_h
class Tile{
private:
    Food food;
    Agent agent;
    int xCoord, yCoord;
public:
    /// Constructs a Hex
    Tile(int x, int y, Agent agent, Food food) {
        setCoords(x, y);
        setFood(food);
        setAgent(agent);
    }
    /// Sets the coordinates of the Hex
    void setCoords(int x, int y) {
        xCoord = x;
        yCoord = y;
    }
    /// Checks if the Hex contains an Agent
    bool containsAgent() {
        return true;
    }
    /// Checks if the Hex contains Food
    bool containsFood() {
        return true;
    }
}
#endif /* Tile_h */
