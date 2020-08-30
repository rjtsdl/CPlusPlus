//
//  a1293ShortestPathInAGridWithObstaclesElimination.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        /* If current K is greater than total manhattan distance, just return m+n-2 right away */
        if (k >= m + n - 3)
            return m + n -2;
        vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> minObstacles(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        int result = INT_MAX;
        /* To precompute the minObstacles at every index in O(m*n) using Dynamic Programming*/
        for (int i = grid.size()-1; i >= 0; i--) {
            for (int j = grid[0].size()-1; j >= 0; j--) {
                if (i == grid.size()-1 && j == grid[0].size()-1) {
                    minObstacles[i][j] = 0;
                    continue;
                }
                else if (i == grid.size()-1)
                    minObstacles[i][j] = minObstacles[i][j+1];
                else if (j == grid[0].size()-1)
                    minObstacles[i][j] = minObstacles[i+1][j];
                else
                    minObstacles[i][j] = min(minObstacles[i+1][j], minObstacles[i][j+1]);
                if (grid[i][j] == 1)
                    minObstacles[i][j] += 1;
            }
        }
        DFS(grid, 0, 0, flag, result, k, 0, minObstacles);
        return result != INT_MAX ? result : -1;
    }
    
    int DFS(vector<vector<int>>& grid, int row, int column, vector<vector<bool>>& flag,
            int& result, int k, int steps, vector<vector<int>>& minObstacles)
    {
        if (k >= minObstacles[row][column]) {
            /* we can safely "jump" from current position to destination and no further computation needed*/
            int temp = steps + (grid.size() - row + grid[0].size() - column - 2);
            result = min(result, temp);
            return 1;
        }
        /* Mark current position as true and check for four directions*/
        flag[row][column] = true;
        if (column+1 < grid[0].size() && k >= 0 && steps+1 < result && flag[row][column+1] == false) {
            int temp = DFS(grid, row, column+1, flag, result, grid[row][column+1] == 1 ? k-1 : k, steps+1, minObstacles);
            if (temp)
                return 1;
        }
        if (row+1 < grid.size() && k >= 0 && steps+1 < result && flag[row+1][column] == false) {
            int temp = DFS(grid, row+1, column, flag, result, grid[row+1][column] == 1 ? k-1 : k, steps+1, minObstacles);
            if (temp)
                return 1;
        }
        if (column-1 >= 0 && k >= 0 && steps+1 < result && flag[row][column-1] == false) {
            int temp = DFS(grid, row, column-1, flag, result, grid[row][column-1] == 1 ? k-1 : k, steps+1, minObstacles);
            if (temp)
                return 1;
        }
        if (row-1 >= 0 && k >= 0 && steps+1 < result && flag[row-1][column] == false) {
            int temp = DFS(grid, row-1, column, flag, result, grid[row-1][column] == 1 ? k-1 : k, steps+1, minObstacles);
            if (temp)
                return 1;
        }
        flag[row][column] = false;
        return 0;
    }
};
