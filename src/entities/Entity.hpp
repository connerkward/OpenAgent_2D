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

enum ENTITY_TYPE { BLANK, AGENT, FOOD, OBSTACLE };

class Entity {
private:
	bool onFlag;
protected:
	Environment& viewOfEnvironment;
public:
	ENTITY_TYPE entityType;
	int xLoc;
	int yLoc;
	std::string entityChar;

	Entity(Environment& env, int x, int y);

	void changeState();
	bool isOn();

	friend std::ostream& operator << (std::ostream& os, const Entity& thisEntity);
};

#endif /* Entity_hpp */
