//
//  a778SwiminRisingWater.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        vector<vector<int>> minT(N, vector<int>(N, INT_MAX/2));
        
        
        while (!pq.empty()) {
            vector<int> t = pq.top();
            pq.pop();
            
            int r = t[1];
            int c = t[2];
            int ti = t[0];
            
            if (minT[r][c] < INT_MAX/2) {
                // visited
                continue;
            }
            
            if (r == N-1 && c == N-1) return ti;
            
            minT[r][c] = ti;
            
            if (r-1 >= 0 && minT[r-1][c] == INT_MAX/2) {
                pq.push({max(grid[r-1][c],ti), r-1, c});
            }
            
            if (c-1 >= 0 && minT[r][c-1] == INT_MAX/2) {
                pq.push({max(grid[r][c-1],ti), r, c-1});
            }
            
            if (r+1 < N && minT[r+1][c] == INT_MAX/2) {
                pq.push({max(grid[r+1][c], ti), r+1, c});
            }
            if (c+1 < N && minT[r][c+1] == INT_MAX/2) {
                pq.push({max(grid[r][c+1], ti), r, c+1});
            }
        }
        
        return minT[N-1][N-1] == INT_MAX/2 ? -1: minT[N-1][N-1];
    }
};
