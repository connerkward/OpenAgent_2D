/**
	A data structure representing the environment an Agent lives in.

	A Board is made up of Hexes, which can contain either Food or
	Agents.
	When Agents move across the boundaries of a Board they appear on 
	the opposite side of the Board (periodic boundary conditions).

*/
#include <string>
#include "Board.h"
/// TODO: Add representation

/// Should the board have a border?
/// Which class has responsibility for enforcing PBCs?

/// TODO: Add a board populator

/// TODO: Create a string representation for the Board

//Constructor
Board::Board(int sizex, int sizey) {
    return;
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
    return "food"; // typedef()
}
