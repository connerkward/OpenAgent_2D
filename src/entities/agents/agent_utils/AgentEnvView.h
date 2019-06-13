// Add relevant #include's here
#include <vector>
#include "AgentTileView.h"
#include "../../../environments/Tile.h"
#include "../../../environments/Environment.hpp"

using std::vector;

class AgentEnvView {
private:
	vector<vector<AgentTileView>> envView;
	int agentX, agentY;

public:
	const int sizeX;
	const int sizeY;

	AgentEnvView(int x, int y, int agentLocX, int agentLocY);

	void updateTileViews(vector<Tile>& tiles);
	void updateTileView(Tile&);
	void updateAgentLocation(int x, int y);
	
	const AgentTileView& getTileView(int x, int y);
	vector<const AgentTileView>& neighbors(int x, int y);

	bool viewExists(int x, int y);
};