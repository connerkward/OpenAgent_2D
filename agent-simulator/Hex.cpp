/**
	This object represents a location on a Board, and can contain Food,
	an Agent, or both.
*/
class Tile {

	private:
		Food food;
		Agent agent;
		int xCoord, yCoord;
	public:
		/// Constructs a Hex
		Tile(int x, int y, Agent agent, Food food) {
			setCoords(x, y);
			setFood(food);
			setAgent(agent);
		}
		/// Sets the coordinates of the Hex
		void setCoords(int x, int y) {
			xCoord = x;
			yCoord = y;
		}
		/// Checks if the Hex contains an Agent
		bool containsAgent() {
			return true;
		}
		/// Checks if the Hex contains Food
		bool containsFood() {
			return true;
		}
};