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
class Board {
public:
    Board(int sizex=0, int sizey=0); // defaults , not sure if necessary
    bool checkifvalid(int boardlocation[2]);
    std::string check(int boardlocation[2]);
    int boardsize();
    // ^ wont return string, will return reference to object
private:
    const int DEFAULTSIZE = 12; // default for grid, not necessary
    int sizex;
    int sizey;
    //Tile grid[10][10]; // for implementation of 2d array of tiles
};

#endif /* Board_h */
