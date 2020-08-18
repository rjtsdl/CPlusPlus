//
//  a1162AsFarFromLandAsPossible.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        int zeros = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }else{
                    zeros++;
                }
            }
        }
        
        if(q.empty()){
            return -1;
        }
        
        if(zeros == 0){
            return -1;
        }
        
        int x[4] = {0,0,1,-1};
        int y[4] = {1,-1,0,0};
        int ans = 0;
        
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                auto temp = q.front();
                q.pop();
                
                for(int k=0;k<4;k++){
                    int r = temp.first + x[k];
                    int c = temp.second + y[k];
                    
                    if(r>=0 and r<n and c>=0 and c<m and dist[temp.first][temp.second] + 1 < dist[r][c]){
                        dist[r][c] = dist[temp.first][temp.second] + 1;
                        ans = max(ans,dist[r][c]);
                        q.push({r,c});
                    }
                }
            }
        }
        
        return ans;
    }
};
