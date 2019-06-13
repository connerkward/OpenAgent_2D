/**
 This object represents a location on a Board, and can contain Food,
 an Agent, or both.
 */

#include "Tile.h"

Tile::Tile(int x, int y) : xPos(x), yPos(y) {
	entity = nullptr;
}

void Tile::placeEntity(Entity& newEntity) {
	entity = &newEntity;
}

void Tile::removeEntity() {
	entity = nullptr;
}

ENTITY_TYPE Tile::getEntityType() {
	return (*entity).entityType;
}

std::ostream& operator << (std::ostream& os, const Tile& thisTile) {
    if (thisTile.entity != nullptr) { 
        os << thisTile.entity->entityChar;
        return os;
    }
    else {
        os << '-';
        return os;
    }
}

std::string Tile::tostring() {
    std::string returnstring;
    if (this->entity != nullptr) {
        returnstring += this->entity->entityChar;
        return returnstring;
    }
    else {
        returnstring += '-';
        return returnstring;
    }
}

