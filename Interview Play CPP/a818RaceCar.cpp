//
//  a818RaceCar.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

class Solution {
public:
    struct node{
        double steps, pos, speed;
    };
    int racecar(int target) {
        queue<node> q;
        q.push({0, 0, 1});
        while(!q.empty()){
            double steps = q.front().steps;
            double pos = q.front().pos;
            double speed = q.front().speed;
            if(pos == target)   return steps;
            q.pop();
            q.push({steps+1, pos + speed, 2*speed});
            if(speed > 0 && (pos + speed) > target)
                q.push({steps+1, pos, -1});
            else if(speed <= 0 && (pos + speed) < target)
                q.push({steps+1, pos, 1});
        }
        return 0;
    }
};
