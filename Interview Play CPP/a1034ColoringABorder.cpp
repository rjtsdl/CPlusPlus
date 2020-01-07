//
//  a1034ColoringABorder.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void findComponent(vector<vector<int>>& grid, int r0, int c0, int color, vector<pair<int,int>>& component) {
    int n = grid.size(), m = grid[0].size();
    if (r0 >= n or c0 >= m or r0 < 0 or c0 < 0 or grid[r0][c0] != color) return;
    
    component.push_back({r0, c0});
    grid[r0][c0] = 0;
    findComponent(grid, r0 + 1, c0, color, component);
    findComponent(grid, r0 - 1, c0, color, component);
    findComponent(grid, r0, c0 + 1, color, component);
    findComponent(grid, r0, c0 - 1, color, component);
    grid[r0][c0] = color;
}

bool isABorderCell(int r0, int c0, vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    return (r0 == n-1 or (r0 == 0) or c0 == m-1 or (c0 == 0)) or
           (r0 - 1 >= 0 and grid[r0 - 1][c0]  != grid[r0][c0]) or
           (r0 + 1 < n  and grid[r0 + 1][c0]  != grid[r0][c0]) or
           (c0 - 1 >= 0 and grid[r0][c0 - 1]  != grid[r0][c0]) or
           (c0 + 1 < m  and grid[r0][c0 + 1]  != grid[r0][c0]);
}

vector<pair<int,int>> findBorder(vector<vector<int>>& grid, vector<pair<int,int>>& component) {
    vector<pair<int,int>> border;
    int n = grid.size(), m = grid[0].size();
    for (auto p : component) {
        if (isABorderCell(p.first, p.second, grid)) {
            border.push_back(p);
        }
    }
    return border;
}
vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    vector<pair<int,int>> component;
    findComponent(grid, r0, c0, grid[r0][c0], component);
    vector<pair<int,int>> border = findBorder(grid, component);
    for (auto& p : border) {
        grid[p.first][p.second] = color;
    }
    return grid;
}
};
