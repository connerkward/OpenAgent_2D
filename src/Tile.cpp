/**
 This object represents a location on a Board, and can contain Food,
 an Agent, or both.
 */
#include "Tile.h"

// CONSTRUCTORS
//Default Constructor
Tile::Tile(){
    int coord[] = {0,0};
    setCoords(coord);
    entityChar = "-";
}
Tile::Tile(int coord[2]){
    setCoords(coord);
    entityChar = "-";
}

// SETTERS
/// Set Tile Coordinate
void Tile::setCoords(int coord[2]) {
    Tilex = coord[0];
    Tiley = coord[1];
}

// Set Pointer
void Tile::updatePointerWith(Entity entToMove){ // the question of the century
    entityChar = entToMove.entityChar;
    ent = &entToMove;
}



// GETTERS
///// Checks if the Hex contains an Agent
//bool Tile::containsAgent() {
//    return true;
//}
///// Checks if the Hex contains Food
//bool Tile::containsFood() {
//    return true;
//}

// PRINTERS
std::ostream& operator<<(std::ostream& os, const Tile& thisTile)
{
    os << thisTile.entityChar;
    return os;
}
