//
//  a827MakingALargeIsland.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    const vector<vector<int>> fourDirection {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m ==0 || n == 0) return 0;
        // map from i, j
        // to adjacent island index
        int island = -1;
        map<vector<int>, set<int>> mp;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> islandSize;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] ) {
                    islandSize.push_back(dfs(grid, visited, mp, i, j, ++island));
                }
            }
        }
        
        if (islandSize.empty()) return 1;
        
        int maxSize = *max_element(islandSize.begin(), islandSize.end());
        
        for (auto kv : mp) {
            int adc = 1;
            for (int i : kv.second) {
                adc += islandSize[i];
            }
            
            maxSize = max(maxSize, adc);
        }
        
        return maxSize;
    }
    
    int dfs(vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
            map<vector<int>, set<int>>& mp,
             int i, int j, int island) {
        if (grid[i][j] == 0) {
            mp[{i, j}].insert(island);
            return 0;
        }
        visited[i][j] = true;
        int ret = 1;
        for (vector<int> d : fourDirection) {
            if (i+d[0] >=0 && j + d[1] >=0 && i+d[0] < grid.size() && j+d[1]<grid[0].size()) {
                if (!visited[i+d[0]][j+d[1]]) {
                    ret += dfs(grid, visited, mp, i+d[0], j+d[1], island);
                }
            }
        }
        return ret;
    }
};
