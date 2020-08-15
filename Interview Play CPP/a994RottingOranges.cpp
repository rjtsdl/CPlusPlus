//
//  a994RottingOranges.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount = 0;
        vector<vector<int>> rottens;
        vector<vector<int>> nextRottens;
        int mins = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) {
                    rottens.push_back({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0,1}, {0, -1}};
        while (!rottens.empty()) {
            for (auto r : rottens) {
                for (auto d : dir) {
                    if ( r[0]+d[0] >=0 && r[0]+d[0] < grid.size() && r[1]+d[1] >=0 && r[1]+d[1] < grid[0].size() &&
                        grid[r[0]+d[0]][r[1]+d[1]] == 1) {
                        freshCount--;
                        grid[r[0]+d[0]][r[1]+d[1]] = 2;
                        nextRottens.push_back({r[0]+d[0], r[1]+d[1]});
                    }
                }
            }
            if (!nextRottens.empty()) mins++;
            rottens = nextRottens;
            nextRottens = vector<vector<int>>();
        }
        
        if (freshCount > 0 ) {
            return -1;
        }
        
        return mins;
        
    }
};
