//
//  a1254NumberofClosedIslands.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    int row, col;
        
        //regular DFS, extra flag setting
        void dfs (vector<vector<int>>& grid, int i, int j, bool& reachBound)
        {
            if (i>=0 && i<row &&j>=0 && j<col && grid[i][j]==0)
            {
                grid[i][j]=-1; //visited? flip to -1
                if (i==0||i==row-1 ||j==0 ||j==col-1)
                    reachBound=true;
                
                dfs (grid, i,j-1, reachBound);
                dfs (grid, i,j+1, reachBound);
                dfs (grid, i-1,j, reachBound);
                dfs (grid, i+1,j, reachBound);
            }
        }
    public:
        int closedIsland(vector<vector<int>>& grid) {
            row = grid.size();
            if (row==0) return 0;
            col= grid[0].size();
            
            int count =0;
            
            for (int i=0; i<row; i++)
                for (int j =0; j<col; j++)
                {
                    if (grid[i][j]==0)
                    {
                        bool reachBound = false;
                        dfs (grid, i, j, reachBound);
                        
                        if (!reachBound)
                            count++;
                    }
                }
            
            return count;
            
            
        }
};
