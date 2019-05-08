/**
 This object represents a location on a Board, and can contain Food,
 an Agent, or both.
 */

#include "Tile.h"

// CONSTRUCTORS
Tile::Tile(int x, int y) {
	coordinates[0] = x;
	coordinates[1] = y;
	entityWithin = nullptr;
}

bool Tile::placeEntity(Entity& entity) {
	if (entityWithin != nullptr) {
		return false;
	}
	else {
		entityWithin = &entity;
		return true;
	}
}

bool Tile::removeEntity() {
	entityWithin = nullptr;
	return true;
}

bool Tile::occupied() {
	return entityWithin != nullptr;
}

bool Tile::containsEntity(ENTITY_TYPE entityType) {
	if (entityWithin != nullptr && entityWithin->entityType == entityType) {
		return true;
	}
	return false;
}

std::ostream& operator << (std::ostream& os, const Tile& thisTile) {
    if (thisTile.entityWithin != nullptr) { 
        os << thisTile.entityWithin->entityChar;
        return os;
    }
    else {
        os << '-';
        return os;
    }
}

