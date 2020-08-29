//
//  a980UniquePathsIII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    int totalpath = 0;
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int totalzero)
    {
        if(i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1
           || grid[i][j] == -1 || (grid[i][j] == 2 && totalzero != 0) || grid[i][j] == 99)
            return;
        
        if(grid[i][j] == 2 && totalzero == 0)
            totalpath++;
        if(grid[i][j] == 0)
            totalzero--;
        //backtracking
        
        int temp = grid[i][j];
        grid[i][j] = 99;
        
        dfs(grid, i+1, j, totalzero);
        dfs(grid, i-1, j, totalzero);
        dfs(grid, i, j-1, totalzero);
        dfs(grid, i, j+1, totalzero);
        
        grid[i][j] = temp;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {

        int totalzero = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0)
                    totalzero++;
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,totalzero);
                }
            }
        }
        return totalpath;
    }
};
