#include "AgentTileView.h"

AgentTileView::AgentTileView(Tile& tile) : x(tile.xPos), y(tile.yPos) {
	entity = BLANK;
	visited = false;
	addEntity(tile.getEntityType());
}

AgentTileView::AgentTileView(int x, int y) : x(x), y(y) {
	entity = BLANK;
	visited = false;
}

void AgentTileView::addEntity(ENTITY_TYPE newEntity) {
	entity = newEntity;
}

void AgentTileView::removeEntity() {
	addEntity(BLANK);
}

ENTITY_TYPE AgentTileView::getEntity() {
	return entity;
}
