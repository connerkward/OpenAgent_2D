#include "../../Entity.hpp"
#include "../../../environments/Tile.h"
#include <vector>

using std::vector;

/* This class represents a node in the Agent's environment graph. */
class AgentTileView {
private:
	ENTITY_TYPE entity;
	bool visited;

public:
	const int x;
	const int y;
	
	AgentTileView(Tile& tile);
	AgentTileView(int x, int y);

	void addEntity(ENTITY_TYPE newEntity);
	void removeEntity();
	ENTITY_TYPE getEntity();
};