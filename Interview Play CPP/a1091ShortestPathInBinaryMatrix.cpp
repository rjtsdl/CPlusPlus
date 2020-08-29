//
//  a1091ShortestPathInBinaryMatrix.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       if(grid.size() == 0 || grid[0].size() == 0 || grid[0][0] != 0)
            return -1;
        
        int n = grid.size();
        if(grid[n-1][n-1] != 0) return -1;
        
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        q.push({0, 0});
        visited.insert({0, 0});
        
        int level = 0;
        while(!q.empty())
        {
            int count = q.size();
            while(count--)
            {
                auto curr = q.front();
                q.pop();
                
                if(curr.first == n-1 && curr.second == n-1)
                    return level+1;
                
                for(auto k : dir)
                {
                    int x = curr.first + k[0];
                    int y = curr.second + k[1];
                    
                    if(x < 0 || y < 0 || x >= n || y >= n || visited.find({x, y}) != visited.end()) continue;
                    if(grid[x][y] == 0)
                    {
                        visited.insert({x, y});
                        q.push({x, y});
                    }
                }
            }
            
            level++;
        }
        
        return -1;
    }
};
