//
//  FoodManager.hpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef FoodManager_hpp
#define FoodManager_hpp
#include "Food.h"
#include "EntityManager.hpp"

class FoodManager : public EntityManager {
public:
    FoodManager(int n, Board &board);
    Food& spawn(int coords[2]);
    void despawn(Food& entity);
private:
    void populate(int n);
    int number;
    std::vector<Food> foods;
    Food& findAvail();
    

};
#endif /* FoodManager_hpp */
