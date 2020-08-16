//
//  a1041RobotBoundedInCircle.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0, y = 0;
        int facing = 0;
        for(int i=0; i<instructions.size(); i++){
            if(instructions[i] == 'L') facing = (facing + 3) % 4;
            else if(instructions[i] == 'R') facing = (facing + 1) % 4;
            else {
                x += dir[facing].first;
                y += dir[facing].second;
            }
        }
        return (x == 0 && y == 0) || facing != 0;
    }
};
