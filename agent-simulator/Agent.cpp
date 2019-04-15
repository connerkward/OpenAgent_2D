#include "Food.cpp"
#include<iostream>
using namespace std;

class Agent {
    int health = 0;
    int playercord [2];
	
	/// If there is Food in the Agent's Hex, it will eat it
    
    void checkCollision(){
        // case statement
        return;
    }
    
	void eat(Food thisfood) {
		/// Eating Food will grant health proportional to value of Food
        health = thisfood.healthgain;
		return;
	}

	/// MOVE
    // param vec is pointer to first element of vector (direction) array
	void move(int *vec) {
        playercord[0] += vec[0];
        playercord[1] += vec[1];
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
            //if([xmove,ymove] is inhabited on grid){
                //case or array of cases -> this we gotta discuss
            //}
            // ELSE MOVE
            //else{
                //move([xmove,ymove]);
            //}
        }
		return;
	}

	/// Reduces the health of the Agent by one. 
	void age() {
		health -= 1;
	}

};
