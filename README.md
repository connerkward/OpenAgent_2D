# agent-simulator
Models simple 'agents', these agents interact with each other, the static environment, and the dynamic environment. 

~Shipped~ 
- Ascii visualization layer 
- Agent Consumables 
- Agent-Obstable Collision
- Perlin (Simplex) Noise Random Map Generation 
- Agent-Evironment Action Framework
- Environment-Tile Framework
- Agent AI Goal Determination
- Agent Life Cycle 
- A roguelike terminal visualization for nerds

~!Currently Testing!~
- Field of View using Bresenham Raycasting (Direct Goal Sensing)
- Converting map files to Environment Objects 
- Scent (Indirect Goal Sensing)

~Under Development~
- Agent-Agent Interaction (Procreation and Death)
- A* Pathfinding (Usecase TBD)
- Unified Random Seed (relatively deterministic map generation and simulation)


A primary constraint in this project is unlike RTS games like Starcraft or simulation games like Cities Skylines, 
We wanted to stay true to the concept of an independent agent, one that did not have full sensory access to its environment. 

Therefore, the project was chosen to be written in C++ instead of the teams more familiar Python, for efficiency at runtime. 

Furthermore, the project is intended to be an easy to use open source framework for creation and testing of other discrete-space algorithms. 
After completeing the basic framework and our intended project goals for our little Agents, one can only hope we bravely go into 

FLOAT SPACE.

- Star Gods Development Team 

[CodeBros]
