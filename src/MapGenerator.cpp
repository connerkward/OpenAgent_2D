//
//  MapGenerator.cpp
//  src
//
//  Created by Conner K Ward on 5/28/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "MapGenerator.hpp"

MapGenerator::MapGenerator(){
    
}
std::string MapGenerator::generate(std::string name){
    std::string levelstring;
    // generate grid based on input
    const static int width = 100;
    const static int height = 100;
    const static float freq = (width*height)/(width+height)/10;
    std::cout << freq << std::endl;
    const static float obstacleThreshold = -0.1;
    
    // Initialize noise generator
    FractalNoise noiseMaker;
    noiseMaker.setBaseFrequency(3.0f);
    
    // Initialize array to store noise values
    float noiseArray[width*height];
    
    
    
    /// generate perlin noise (simplex) * modifiers, for each object type
    
    // Generate a noise value for each pixel
    float invWidth = 1.0f / float(width);
    float invHeight = 1.0f / float(height);
    
    std::ofstream myfile;
    //myfile.open("map2.txt");
    myfile.open(name);
    
    srand((unsigned)time(0));
    
    for (int x=0; x<width; ++x){
        for (int y=0; y<height; ++y) {
            if(x == 0 || y == 0 || y == height-1 || x == width-1){
                //std::cout << "*";
                levelstring.append("*");
                myfile << "*";
            }
            else{
                noiseArray[y*width + x] = noiseMaker.noise(float(x)*invWidth, float(y)*invHeight, 0.72);
                std::cout << noiseArray[y*width + x] << std::endl;
                int randnum = rand() % 100 + 1;
                std::cout << randnum << std::endl;
                if (noiseArray[y*width + x] > obstacleThreshold){
                    if (rand() % 100 + 1 > 99.9){
                        levelstring.append("@");
                        myfile << "@";
                        //std::cout << "&";
                    }
                    else if (rand() % 100 + 1 > 98){
                        levelstring.append("&");
                        myfile << "&";
                        //std::cout << "&";
                    }
                    else{
                        levelstring.append("-");
                        myfile << "-";
                    }
                    
                }
                else{
                    //std::cout << "*";
                    levelstring.append("*");
                    myfile << "*";
                }
                
            }
        }
        //std::cout << std::endl;
        levelstring.append("\n");
        myfile << "\n";
    }
    myfile.close();
    
    // straight lines such as walls may need a different or variant algo
    // overlay (granulate) the noise
    // clip certain float values on the noise based on object type
    // distribute object types on grid for values above clip
    
    // auto generate grid edges
    
    // export as custom .map file or .txt file
    /// allow board constructor to take in .txt file arg which defaults to calling map generator
    
    
    return levelstring;
}

    
    

