/**
	A representation of food in the agent's environment.

	Food will have a certain nutrition value. When eaten by an
	Agent, the Agent will gain health equivalent to the nutrition
	value of the Food.

*/
#include "Food.h"
//#include "Board.h"

Food::Food(Environment& board) : Entity(board){
    healthgain = 1;
    entityChar = "$"; // what can I say, its the dough 
    onFlag = true;
}
