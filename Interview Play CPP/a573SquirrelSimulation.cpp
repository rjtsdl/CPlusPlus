//
//  a573SquirrelSimulation.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int tot_dist = 0, d = INT_MIN;
        for (vector<int> nut: nuts) {
            tot_dist += (distance(nut, tree) * 2);
            d = max(d, distance(nut, tree) - distance(nut, squirrel));
        }
        return tot_dist - d;
    }
    
    int distance(vector<int> a, vector<int> b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};
