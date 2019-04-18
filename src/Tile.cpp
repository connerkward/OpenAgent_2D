/**
 This object represents a location on a Board, and can contain Food,
 an Agent, or both.
 */
#include <iostream>
#include "Tile.h"
//Tile::Tile(int coord[2], Agent a, Food f) : food(f), agent(a){
//    setCoords(coord);
//}

Tile::Tile(){
    int coord[] = {0,0};
    setCoords(coord);
    tileChar = "-";
}
Tile::Tile(int coord[2]){
    setCoords(coord);
    tileChar = "-";
}

/// Sets the coordinates of the Hex
void Tile::setCoords(int coord[2]) {
    Tilex = coord[0];
    Tiley = coord[0];
}
/// Checks if the Hex contains an Agent
bool Tile::containsAgent() {
    return true;
}
/// Checks if the Hex contains Food
bool Tile::containsFood() {
    return true;
}

//overloads the << printer 
std::ostream& operator<<(std::ostream& os, const Tile& tile)
{
    os << tile.tileChar;
    return os;
}
