//
//  a200NumberofIslands.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    int islandCount;
    vector<int> dir;
public:
    int numIslands(vector<vector<char>>& grid) {
        islandCount = 0;
        dir = {1,0,-1,0,1};
        for (int i = 0; i< grid.size(); i++) {
            for (int j =0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j);
                }
            }
        }
        return islandCount;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++) {
            if (i + dir[k] >=0 && i+dir[k] < grid.size()
                && j+dir[k+1] >=0 && j+dir[k+1] < grid[0].size() &&
                grid[i+dir[k]][j+dir[k+1]] == '1') {
                dfs(grid, i+dir[k], j+dir[k+1]);
            }
        }
    }
};
