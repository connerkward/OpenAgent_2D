//
//  AgentManager.cpp
//  src
//
//  Created by Conner K Ward on 5/2/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//
#include "Board.h"
#include "AgentManager.hpp"

// CONSTRUCTORS
AgentManager::AgentManager(int anum , Board &board) : internalBoard(board), agentNumber(anum){
    populateAgents(agentNumber, internalBoard);
}


// PRIVATE HELPERS
void AgentManager::populateAgents(int anum, Board &board){
    Agent emptyAgent(board); // pointer to this instanc of Board
    agents.resize(anum, emptyAgent);
}

Agent& AgentManager::findAvailAgent(){
    // iterate through internal agents vector till one finds an avail agent
    for (int i =0; i < agentNumber; i++){
        if (!agents[i].onFlag){
            agents[i].onFlag = true;
            return agents[i];
        }
    }
    return agents[0];
}
agentMovePackage AgentManager::moveAgents(){ // set paramter to type of move?
    agentMovePackage agentMovestruct;
    for (int i =0; i < agentNumber; i++){
        if (agents[i].onFlag){
            agentMovestruct.addAgentMovePair(agents[i], agents[i].randomMove());
        }
    }
    return agentMovestruct;
}

// BOARD ACCESS
agentMovePackage AgentManager::getMoves(){
    return moveAgents();
}
Agent& AgentManager::spawnAgent(){
    return findAvailAgent();
}
void AgentManager::despawnAgent(Agent& agent){
    agent.onFlag = false;
}
int* AgentManager::getAgentCoords(Agent& agent){
    return agent.agentCoord;
}
