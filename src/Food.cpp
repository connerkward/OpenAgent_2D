/**
	A representation of food in the agent's environment.

	Food will have a certain nutrition value. When eaten by an
	Agent, the Agent will gain health equivalent to the nutrition
	value of the Food.

*/
#include "Food.h"

Food::Food(){
    healthgain = 1;
    entityChar = "$";
}
