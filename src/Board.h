//
//  Board.h
//  agent-simulator
//
//  Created by Conner K Ward on 4/15/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include <string>
#include <vector>
#include "Tile.h"
//#include "Agent.h"
class Agent;

class Board {
public:
    Board(int sizex=0, int sizey=0); // defaults , not sure if necessary
    bool checkifvalid(int boardlocation[2]);
    std::string check(int boardlocation[2]);
    int boardsize();
    std::vector<std::vector<Tile>> grid;
    void spawnAgent(Agent &agent, int boardlocation[2]);
    void updateBoard();
    
private:
    const int DEFAULTSIZE = 12; // default for grid, not necessary
    int sizex;
    int sizey;
};

#endif /* Board_h */
