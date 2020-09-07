//
//  a1219PathwithMaximumGold.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int x[4]={0,-1,0,1};
    int y[4]={-1,0,1,0};
    void dfs(vector<vector<int>>&grid,int i,int j,int out,int &ans){
        if(i<0 ||  j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            ans=max(ans,out);
            return;
        }
        int temp=grid[i][j];
        out+=temp;
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            dfs(grid,i+x[k],j+y[k],out,ans);
        }
        grid[i][j]=temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    int out=0;
                    dfs(grid,i,j,out,ans);
                }
            }
        }
        return ans;
    }
};
