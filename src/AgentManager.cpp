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
AgentManager::AgentManager(int n , Board &board) : EntityManager(n,board){
    populate(n);
}


// PRIVATE HELPERS
void AgentManager::populate(int n){
    Agent emptyAgent(internalBoard); // pointer to this instanc of Board
    agents.resize(n, emptyAgent);
}

Agent& AgentManager::findAvail(){
    // iterate through internal agents vector till one finds an avail agent
    for (int i =0; i < number; i++){
        if (!agents[i].onFlag){
            agents[i].onFlag = true;
            return agents[i];
        }
    }
    return agents[0];
}

agentMovePackage AgentManager::moveAgents(){ // set paramter to type of move?
    agentMovePackage agentMovestruct;
    for (int i =0; i < number; i++){
        if (agents[i].onFlag){
            std::cout << "agent current coord:" << agents[i].coord[0] << agents[i].coord[1] << std::endl;
            agentMovestruct.addAgentMovePair(agents[i], agents[i].randomMove());
            
        }
    }
    return agentMovestruct;
}

// BOARD ACCESS
agentMovePackage AgentManager::getMoves(){
    return moveAgents();
}
Agent& AgentManager::spawn(int coords[2]){
    Agent& agent = findAvail();
        std::cout << "spawn at" << coords[0] << "," << coords[1] << std::endl;
    agent.setAgentCoord(coords);
    std::cout << "agentcoord" << agent.coord[0] << "," << agent.coord[1] << std::endl;
    
    return agent;
}
void AgentManager::despawn(Agent& agent){
    agent.onFlag = false;
}
int* AgentManager::getAgentCoords(Agent& agent){
    return agent.coord;
}
