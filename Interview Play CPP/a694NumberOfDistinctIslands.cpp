//
//  a694NumberOfDistinctIslands.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    unordered_set<string> us;
    void findIsland(vector<vector<int>>& grid, string &s, int x, int y, int startx, int starty){
        if(x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0 || !grid[x][y] )return;
        grid[x][y] = 0;
        s += to_string(x-startx) + to_string(y-starty) + ")";
        findIsland(grid, s, x-1, y, startx, starty);
        findIsland(grid, s, x+1, y, startx, starty);
        findIsland(grid, s, x, y-1, startx, starty);
        findIsland(grid, s, x, y+1, startx, starty);
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    string tmp = "";
                    findIsland(grid,tmp,i,j,i,j);
                    us.insert(tmp);
                }
            }
        }
        return us.size();
    }
};
