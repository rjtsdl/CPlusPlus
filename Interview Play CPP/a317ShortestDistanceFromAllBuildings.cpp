//
//  a317ShortestDistanceFromAllBuildings.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValid(int x0, int y0, int m, int n){
        return (x0>=0 && x0<m && y0>=0 && y0<n);
    }
    
    void bfs(vector<vector<int>> & grid, int i, int j, vector<vector<int>> mat, vector<vector<int>> & dist, int dx[], int dy[], int m, int n, vector<vector<bool>> visited){
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(make_pair(i, j), 0));
        visited[i][j]=true;
        while(!q.empty()){
            pair<int, int> p = (q.front()).first;
            int depth = (q.front()).second;
            int x0 = p.first;
            int y0 = p.second;
            q.pop();
            mat[x0][y0] = depth;
            for(int i=0;i<4;i++){
                int x1 = x0+dx[i];
                int y1 = y0 + dy[i];
                if(isValid(x1, y1, m, n) && grid[x1][y1] == 0 && !visited[x1][y1]){
                    visited[x1][y1] = true;
                    q.push(make_pair(make_pair(x1, y1), depth+1));
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == INT_MAX)
                    dist[i][j] = INT_MAX;
                else if(mat[i][j]!= INT_MAX && dist[i][j]!=INT_MAX)
                    dist[i][j] += mat[i][j];
            }
        }
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        if(n == 0)
            return 0;
        vector<vector<int>> mat(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dist(m, vector<int>(n, 0));
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    bfs(grid, i, j, mat, dist, dx, dy, m, n, visited);
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 && dist[i][j]!= INT_MAX)
                    ans = min(ans, dist[i][j]);
            }
        }
        return ans == INT_MAX?-1:ans;
    }
};
