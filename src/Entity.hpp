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
class Entity{
public:
    Entity();
    std::string entityChar;
};

#endif /* Entity_hpp */
