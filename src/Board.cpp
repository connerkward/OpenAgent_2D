/**
	A data structure representing the environment an Agent lives in.

	A Board is made up of Hexes, which can contain either Food or
	Agents.
	When Agents move across the boundaries of a Board they appear on 
	the opposite side of the Board (periodic boundary conditions).

*/
#include <string>
#include <vector>
#include <iostream>
#include "Board.h"
#include "Agent.h"
using namespace std;
/// TODO: Add representation

/// Should the board have a border?
/// Which class has responsibility for enforcing PBCs?

/// TODO: Add a board populator

/// TODO: Create a string representation for the Board
class Agent;

// CONSTRUCTOR
Board::Board(int x, int y) {
    sizex = x;
    sizey = y;
    Tile emptyTile;
    
    grid.resize(sizey, std::vector<Tile>(sizex, emptyTile));
    for(int i=0; i < sizex; i++){
        for(int j=0; j < sizey; j++){
            if(i == 0 || j == 0 || i == sizey-1 || j == sizex-1){
                grid[i][j].tileChar = "*";
            }
        }
    }
}

// Check if boardlocation is "valid" for traversal,
// Returns true for items, false for walls (obstacle)
bool Board::checkifvalid(int boardlocation[2]){
    return true;
}

// Check what is in boardlocation
// return possibly a reference to the object itself, ie "&object"
// Please baby doll no pointers
// Its too early
// Im going to hurt you
std::string Board::check(int boardlocation[2]){
    return ""; // typedef()
}

int Board::boardsize(){
    return sizex*sizey;
}

void Board::spawnAgent(Agent &agent, int boardlocation[2]){
    Agent &thisboy = agent;
    thisboy.playercord[0] = boardlocation[0];
    thisboy.playercord[1] = boardlocation[1];
    grid[thisboy.playercord[0]][thisboy.playercord[1]].tileChar = "@";
}

void Board::updateBoard(){
    
}
