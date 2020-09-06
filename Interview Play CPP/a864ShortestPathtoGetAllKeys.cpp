//
//  a864ShortestPathtoGetAllKeys.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
    
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        if(n == 0)
            return 0;
        vector<vector<char>> mat(m, vector<char>(n, '.'));
        int x = 0, y = 0;
        int K = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                mat[i][j] = grid[i][j];
                if(mat[i][j] == '@'){
                    x = i;
                    y = j;
                }
                if(mat[i][j] >= 'a' && mat[i][j] <= 'f')
                    K++;
            }
        
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64, false)));
        visited[x][y][0] = true;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {x, y}});
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int carry = q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                q.pop();
                if(carry == ((1 << K) -1 ) )
                   return count;
                for(int i=0;i<4;i++){
                    int k = carry;
                    int x1 = x + dx[i];
                    int y1 = y + dy[i];
                    if(!isValid(x1, y1, m, n) || mat[x1][y1] == '#')
                        continue;
                    if(mat[x1][y1] >= 'a' && mat[x1][y1] <= 'f')
                        k = carry | (1 << (mat[x1][y1] - 'a')  );
                    if(mat[x1][y1] >= 'A' && mat[x1][y1] <= 'F')
                        if(  !(carry &  (1 << (mat[x1][y1] - 'A')   ) ) )
                            continue;
                    if(! visited[x1][y1][k]){
                        visited[x1][y1][k] = true;
                        q.push({k, {x1, y1}});
                    }
                    
                }
            }
            count++;
        }
        return -1;
        
    }
};
