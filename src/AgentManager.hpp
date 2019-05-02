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
// agent manager manages agents, and send agent info to board
// manages the agent vector, finds next avail from stack and returns it when board needs spawn
class Board;

class AgentManager{
public:
    // Constructor
    AgentManager(int anum, Board &board);
    
    // Board Access
    agentMovePackage getMoves();
    Agent& spawnAgent();
    void despawnAgent(Agent& agent);
    int* getAgentCoords(Agent& agent);
    
    // Agent Access
        
private:
    // Internal State
    int agentNumber;
    Board &internalBoard;
    std::vector<Agent> agents;
    
    // Helpers
    void populateAgents(int anum, Board &board);
    Agent& findAvailAgent();
    agentMovePackage moveAgents();
    

};

#endif /* AgentManager_hpp */
