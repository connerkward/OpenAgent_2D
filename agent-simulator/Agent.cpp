#include "Food.cpp"
#include<iostream>
using namespace std;

class Agent {
    int health = 0;
    int playercord [2];
	
	/// EAT
	void eat(Food somefood) {
		/// Eating Food will grant health proportional to value of Food
        health = somefood.healthgain;
		return;
	}

	/// MOVE
	void move(int direction[2]) {
        // param is direction to move,
        //ie [-1,-1] (left and down even if 0,0 is in top left corner)
        playercord[0] += direction[0];
        playercord[1] += direction[1];
		return;
	}

	/// RANDOM MOVE 
	void randomMove() {
        bool findingmove = true;
        while(findingmove == true){
            // GENERATE RANDOM LOCATION
            int xmove = playercord[0] - rand()%2;
            int ymove = playercord[1] - rand()%2;
            
            // IF OBSTACLE COLLISION
            // result = Board.check[xmove,ymove];
            //if(result){
                //switch(result){
                // where Board.check[xmove,ymove] is a function that checks location on board and returns an object type, should it exist, the if should be true
                    //case food:
                        //eat();
                        //move();
                        //break;
                    //case obstacle: // loop around to regen random location
                        //return;
                //}
            //}
            
            // ELSE MOVE
            //else{
                //move([xmove,ymove]);
                //break;
            //}
        }
		return;
	}

	/// Reduces the health of the Agent by one. 
	void age() {
		health -= 1;
	}

};
