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

class Environment;

class Entity{
public:
    Entity(Environment& board);
    Environment& internalBoard;
    bool onFlag; // to flag if agent is active on board, public for now
    std::string entityChar;
    Entity& setCoord(int coord[2]);
    int coord [2];
};

#endif /* Entity_hpp */
