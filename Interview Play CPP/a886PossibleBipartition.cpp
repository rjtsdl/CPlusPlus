//
//  a886PossibleBipartition.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int src,vector<int> &vis,vector<int> &color,int c,vector<vector<int>>& g)
    {
        if(!vis[src])
        {
            vis[src]=1;
          
            color[src]=c;
            
            for(int i=0;i<g[src].size();i++)
            {
                int v=g[src][i];
             
                if(vis[v] && color[v]==c)
                    return false;
                else if(!vis[v])
                {
                    if(!dfs(v,vis,color,1-c,g))
                        return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
     
        vector<vector<int>> graph(N+1);
        int n=N+1;
        for(auto edge:dislikes)
        {
            int u=edge[0];
            int v=edge[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> color(n,-1);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(!dfs(i,vis,color,0,graph))
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
