
//
//  ScentFood.cpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "ScentFood.hpp"
#include "Scent.hpp"

ScentFood::ScentFood(Environment& board, int s) : Food(board) {
    stregth = s;
    entityChar = "&";
    populate(8*stregth);
}

void ScentFood::populate(int n){
    Scent scent(internalBoard, *this);
    scentArray.resize(n, scent);
};
