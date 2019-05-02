//
//  Entity.hpp
//  src
//
// Entity is an abstract base class that holds a string
// which is used to store the char that represents the subclass of an Entity.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <string>
class Board;

class Entity{
public:
    Entity(Board& board);
    Board& internalBoard;
    bool onFlag; // to flag if agent is active on board, public for now
    std::string entityChar;
    int coord [2];
    Entity& setCoord(int coord[2]);
};

#endif /* Entity_hpp */
