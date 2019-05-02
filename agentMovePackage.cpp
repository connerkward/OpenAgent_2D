//
//  agentMovePackage.cpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "agentMovePackage.hpp"

// adds an "Agent Move Pair", containing a reference to an Agent and some move
void agentMovePackage::addAgentMovePair(Agent& agent, int move[2]){
    element elem(agent, move);
    moveArray.push_back(elem);
    numberElems++;
}

agentMovePackage::element::element(Agent& agent, int move[2]) : a(agent){
    this->move[0] = move[0];
    this->move[1] = move[1];
}
