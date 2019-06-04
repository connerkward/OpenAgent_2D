//
//  MapGenerator.cpp
//  src
//
//  Created by Conner K Ward on 5/28/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

#include "MapGenerator.hpp"

MapGenerator::MapGenerator(){
    // generate grid based on input
    const static int width = 100;
    const static int height = 100;
    const static float freq = (width*height)/(width+height)/10;
    std::cout << freq << std::endl;
    
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
    myfile.open("a.txt",std::fstream::in | std::fstream::out | std::fstream::trunc);

    for (int x=0; x<width; ++x){
        for (int y=0; y<height; ++y) {
            if(x == 0 || y == 0 || y == height-1 || x == width-1){
                //std::cout << "*";
                myfile << "*";
            }
            else{
                noiseArray[y*width + x] = noiseMaker.noise(float(x)*invWidth, float(y)*invHeight, 0.72);
                if (noiseArray[y*width + x] > 0){
                    if (noiseArray[y*width + x] > 0.01 && noiseArray[y*width + x] < 0.09){
                        //std::cout << "&";
                        myfile << "&";
                    }
                    else{
                        //std::cout << "-";
                        myfile << "-";
                    }
                        
                    
                }
                else{
                    //std::cout << "*";
                    myfile << "*";
                }
                
            }
        }
        //std::cout << std::endl;
        myfile << "/n";
    }

    myfile.close();

    // straight lines such as walls may need a different or variant algo
    // overlay (granulate) the noise
    // clip certain float values on the noise based on object type
    // distribute object types on grid for values above clip
    
    // auto generate grid edges
    
    // export as custom .map file or .txt file
    /// allow board constructor to take in .txt file arg which defaults to calling map generator
    
}

