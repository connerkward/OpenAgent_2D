//
//  AgentManager.hpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#ifndef AgentManager_hpp
#define AgentManager_hpp
#include "Agent.h"
#include <stdio.h>
#include <vector>
#include "agentMovePackage.hpp"
#include "EntityManager.hpp"
// agent manager manages agents, and send agent info to board
// manages the agent vector, finds next avail from stack and returns it when board needs spawn
class Board;

class AgentManager : public EntityManager{
public:
    // Constructor
    AgentManager(int n, Board &board);
    
    // Board Access
    agentMovePackage getMoves();
    Agent& spawn(int coords[2]);
    void despawn(Agent& agent);
    int* getAgentCoords(Agent& agent);
    
    // Agent Access
        
private:
    // Internal State
    std::vector<Agent> agents;
    
    // Helpers
    void populate(int n);
    Agent& findAvail();
    agentMovePackage moveAgents();
    

};

#endif /* AgentManager_hpp */
