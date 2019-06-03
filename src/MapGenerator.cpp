//
//  MapGenerator.cpp
//  src
//
//  Created by Conner K Ward on 5/28/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "MapGenerator.hpp"

MapGenerator::MapGenerator(int sizeX, int sizeY, int goalFrequency, int obsFrequency, int agentFrequency){
    // generate grid based on input
    // auto generate grid edges
    // generate perlin noise (simplex) * modifiers, for each object type
    // straight lines such as walls may need a different or variant algo
    // overlay (granulate) the noise
    // clip certain float values on the noise based on object type
    // distribute object types on grid for values above clip
    // export as custom .map file or .txt file
    /// allow board constructor to take in .txt file arg which defaults to calling map generator 
}
