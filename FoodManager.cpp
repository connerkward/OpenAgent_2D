//
//  FoodManager.cpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "FoodManager.hpp"
#include <iostream>

// CONSTRUCTORS
FoodManager::FoodManager(int n , Board& board) : EntityManager(n, board){
    populate(n);
}

// PRIVATE HELPERS
void FoodManager::populate(int n){
    Food emptyFood(internalBoard); // pointer to this instanc of Board
    foods.resize(n, emptyFood);
}

void FoodManager::despawn(Food& food){
    food.onFlag = false;
}

Food& FoodManager::spawn(int coords[2]){
    Food& food = findAvail();
    food.setCoord(coords);
    return food;
}
//
//int* FoodManager::getCoords(Food& food){
//    return food.coord;
//}
//
Food& FoodManager::findAvail(){
    // iterate through internal agents vector till one finds an avail agent
    for (int i =0; i < number; i++){
        if (!foods[i].onFlag){
            foods[i].onFlag = true;
            return foods[i];
        }
    }
    return foods[0];
}
