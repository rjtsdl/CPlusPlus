//
//  a505TheMazeII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& d) {
        
        int m = maze.size();
        int n = maze[0].size();
        
        vector<vector<int>> vis(m, vector<int> (n, 0));
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy ={0, 1, 0, -1};
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        
        vector<int> st = {0, start[0], start[1]};
        pq.push(st);
        //vis[start[0]][start[1]] = 1;
        
        while(!pq.empty()) {
                
                vector<int> cur = pq.top();
                pq.pop();
                vis[cur[1]][cur[2]] = 1;
                
                if(cur[1] == d[0] && cur[2] == d[1])
                    return(cur[0]);
                
                for(int i = 0; i < 4; ++i) {
                    int x = cur[1] + dx[i];
                    int y = cur[2] + dy[i];
                    int k = 0;
                    while(x >= 0 && y >= 0 && x < m && y < n && maze[x][y] == 0) {
                        x += dx[i];
                        y += dy[i];
                        k++;
                    }
                    //k--;
                    
                    x -= dx[i];
                    y -= dy[i];
                    
                    
                    if(vis[x][y])
                        continue;
                    
                    vector<int> nxt = {cur[0] + k , x, y};
                    pq.push(nxt);
                    //vis[x][y] = 1;
                }
            
        }
        
        return(-1);
    }
};
