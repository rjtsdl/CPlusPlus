//
//  a1029TwoCityScheduling.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>&b) {
            return a[0] - a[1] < b[0]-b[1];
        });
        
        int total = 0;
        int n = costs.size()/2;
        for (int i =0 ; i < n; ++i) {
            total += costs[i][0] + costs[i+n][1];
        }
        return total;
    }
};
