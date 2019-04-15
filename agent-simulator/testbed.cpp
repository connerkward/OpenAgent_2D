//
//  testbed.cpp
//  agent-simulator
//
//  Created by Conner K Ward on 4/14/19.
//  Copyright © 2019 Conner K Ward. All rights reserved.
//

/*#include <stdio.h>
#include <chrono>
#include <thread>

// to use "cout" without declaring namespace
using namespace std;

// map sizes
const int LEGNTH = 10;
const int WIDTH = 30;
// spawn is set to middle of level
const int spawn[2] =
{
    (LEGNTH)/2,
    (WIDTH)/2
};
// initialized with const's since array is static
std::string grid [LEGNTH][WIDTH];

// main
int main()
{
    // player coordinates
    int playercord[2];
    for(int i = 0; i < LEGNTH; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            // create walls around level
            if (j == 0 || i == 0 || j == WIDTH-1 || i == LEGNTH-1){
                grid[i][j] = "*";
            }
            if (j == 0 || i == 0 || j == WIDTH-1 || i == LEGNTH-1){
                grid[i][j] = "*";
            }
            // create spawn point
            else if(i == spawn[0] && j == spawn[1]){
                grid[i][j] = "-";
                playercord[0] = i;
                playercord[1] = j;            }
            // fill empty squares
            else{
                grid[i][j] = "-";
            }
        }
    }
    
    //running
    bool running = true;
    
    while(running == true){
        //wait so we can see moves
        this_thread::sleep_for(chrono::milliseconds(500));
        bool findingmove = true;
        while(findingmove == true){
            // find random coordinates to move to
            int xmove = playercord[0] - rand()%2;
            int ymove = playercord[1] - rand()%2;
            // if agent hits obstacle
            if(playercord[0] == 0 || playercord[1] == 0){
                
            }
            // else update position
            else{
                playercord[0] = xmove;
                playercord[1] = ymove;
            }
        }
        
        //print grid
        for(int i = 0; i < LEGNTH; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                if(i == playercord[0] && j == playercord[1]){
                    cout << "@";
                }
                else{
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    }
    
    return 0;
};


*/
