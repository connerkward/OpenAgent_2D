//
//  MapGenerator.cpp
//
//  Map Generator generates maps from Perlin-like noise library and creates a text file with the map data.
//  It also exports a string version, which can be function chained into an Environment constructor.
//
//
//  Created by Conner K Ward on 5/28/19.
//  Star Gods Dev Team
//

#ifndef MapGenerator_hpp
#define MapGenerator_hpp
#include "PerlinNoiseCpp-master/Perlin.h"
#include "PerlinNoiseCpp-master/FractalNoise.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>



class MapGenerator{
public:
    MapGenerator();
    std::string generate(std::string name);
    
};
#endif /* MapGenerator_hpp */
