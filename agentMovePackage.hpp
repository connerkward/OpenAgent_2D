//
//  agentMovePackage.hpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef agentMovePackage_hpp
#define agentMovePackage_hpp

#include <stdio.h>
#include <vector>
class Agent;

struct agentMovePackage{
    void addAgentMovePair(Agent& agent, int move[2]);
    int numberElems;
    struct element{
        element(Agent& agent, int move[2]);
        Agent& a;
        int move[2];
    };
    std::vector<element> moveArray;
};
#endif /* agentMovePackage_hpp */
