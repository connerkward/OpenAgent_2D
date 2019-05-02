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
public:
    void addAgentMovePair(Agent& agent, int move[2]);
    void print();
    friend std::ostream& operator<<(std::ostream& os, const agentMovePackage& thispackage);
    int numberElems =0;
    struct element{
        element(Agent& agent, int move[2]);
        Agent& a;
        int move[2];
    };
    std::vector<element> moveArray;
};
#endif /* agentMovePackage_hpp */
