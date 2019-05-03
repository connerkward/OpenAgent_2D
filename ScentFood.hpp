//
//  ScentFood.hpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef ScentFood_hpp
#define ScentFood_hpp
#include "Food.h"
#include "Scent.hpp"
#include <vector>

class Board;
class Scent;

class ScentFood : public Food{
public:
    ScentFood(Environment& board, int s);
    int stregth;
    std::vector <Scent> scentArray;
    void populate(int n);
};
#endif /* ScentFood_hpp */
