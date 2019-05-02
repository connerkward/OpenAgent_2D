/**
 This object represents a location on a Board, and can contain Food,
 an Agent, or both.
 */
#include "Tile.h"

// CONSTRUCTORS
Tile::Tile(){ // find some way to chain constructors perhaps? instead of my repeat code
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
void Tile::updatePointerWith(Entity& entToMove){ // the question of the century
    //std::cout << "ENTITY" << entityChar << std::endl; // debug

    entityChar = entToMove.entityChar;
    ent = &entToMove;
}

void Tile::clearPointer(){
    entityChar = "-";
    ent = nullptr;
}

bool Tile::containsSomething(){
    if (ent == nullptr){
        return false;
    }
    else{
        return true;
    }
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
    if (thisTile.ent != nullptr){ // if this tile's pointer is pointing (is not NULL)
        os << thisTile.ent->entityChar; //print out the char of the object that the pointer points to
        return os;
    }
    else {
        os << thisTile.entityChar; // otherwise pointer is null and use default existing char
        return os;
    }

}
