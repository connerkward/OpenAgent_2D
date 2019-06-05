//
//  MapGenerator.hpp
//  src
//
//  Created by Conner K Ward on 5/28/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
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
    std::string generate();
    
};
#endif /* MapGenerator_hpp */
