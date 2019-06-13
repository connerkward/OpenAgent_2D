//
//  Entity.cpp
//  src
//
//  Created by Conner K Ward on 4/30/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(Environment& env, int x = 0, int y = 0) : viewOfEnvironment(env) {
	xLoc = x;
	yLoc = y;
	entityType = BLANK;
	entityChar = "-";
	onFlag = false;
}

void Entity::changeState() {
	onFlag = !onFlag;
}

bool Entity::isOn() {
	return onFlag;
}

