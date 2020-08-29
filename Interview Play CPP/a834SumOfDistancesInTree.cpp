//
//  a834SumOfDistancesInTree.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/28/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int x,int parent,vector<vector<int>>&graph,vector<int>&cnt,vector<int>&ans)
    {
        cnt[x]=1;
        for(int i=0;i<graph[x].size();i++)
        {
            if(graph[x][i]!=parent)
            {
                dfs(graph[x][i],x,graph,cnt,ans);
                cnt[x]+=cnt[graph[x][i]];
                ans[x]+=ans[graph[x][i]]+cnt[graph[x][i]];
            }
        }
    }
    void dfs1(int x,int parent,vector<vector<int>>&graph,vector<int>&cnt,vector<int>&ans)
    {
        int n=cnt.size();
        if(parent!=-1)
        ans[x]=ans[x]+ans[parent]-(ans[x]+cnt[x])+(n-cnt[x]);//could be simplified,but then it would be difficult to decode.
        for(int i=0;i<graph[x].size();i++)
        {
            if(graph[x][i]!=parent)
            dfs1(graph[x][i],x,graph,cnt,ans);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edg) {
        vector<vector<int>>graph(n);vector<int> ans(n),cnt(n);
        for(int i=0;i<n-1;i++)
        {
            graph[edg[i][0]].push_back(edg[i][1]);
            graph[edg[i][1]].push_back(edg[i][0]);
        }
        dfs(0,-1,graph,cnt,ans);
        dfs1(0,-1,graph,cnt,ans);
        return ans;
    }
};
