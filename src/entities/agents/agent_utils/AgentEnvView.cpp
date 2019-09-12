//#include "AgentEnvView.h"
//
//AgentEnvView::AgentEnvView(int x, int y, int agentLocX, int agentLocY) : sizeX(x), sizeY(y) {
//    agentX = agentLocX;
//    agentY = agentLocY;
//    for (int i = 0; i < sizeX; ++i) {
//        envView.push_back(vector<AgentTileView>());
//        for (int j = 0; i < sizeY; ++j) {
//            envView[i].push_back(AgentTileView(i, j));
//        }
//    }
//}
//
//void AgentEnvView::updateTileViews(vector<Tile>& tiles) {
//    while (!tiles.empty()) {
//        updateTileView(tiles.back());
//        tiles.pop_back();
//    }
//}
//
//void AgentEnvView::updateTileView(Tile& tile) {
//    envView[tile.xPos][tile.yPos].addEntity(tile.getEntityType());
//}
//
//void AgentEnvView::updateAgentLocation(int x, int y) {
//    agentX = x;
//    agentY = y;
//}
//
//const AgentTileView& AgentEnvView::getTileView(int x, int y) {
//    return envView[x][y];
//}
//
//vector<const AgentTileView>& AgentEnvView::neighbors(int x, int y) {
//    vector<const AgentTileView> neighborViews = vector<const AgentTileView>();
//    if (!viewExists(x, y)) {
//        return neighborViews;
//    }
//    else {
//        const AgentTileView& curr = getTileView(x, y);
//        for (int i = -1; i != 2; ++i) {
//            for (int j = -1; j != 2; ++i) {
//                int newX = curr.x + i;
//                int newY = curr.y + j;
//                if (viewExists(newX, newY)) {
//                    neighborViews.push_back(getTileView(newX, newY));
//                }
//            }
//        }
//        return neighborViews;
//    }
//}
//
//bool AgentEnvView::viewExists(int x, int y) {
//    return x >= 0 && x < sizeX && y >= 0 & y < sizeY;
//}
