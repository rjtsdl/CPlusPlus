//
//  a1245TreeDiameter.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> graph(n);
        for(auto e: edges){
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        int maximum = 0;
        vector<bool> visited(n);
        deque<pair<int,int>> q;
        int start = 0;
        for(auto i:{0,1}){
            fill(visited.begin(),visited.end(),false);
            visited[start]=true;
            q.emplace_back(start,0);
            while(!q.empty()){
                auto top = q.front().first;
                auto len = q.front().second;
                if(maximum < len) start = top;
                maximum = max(len,maximum);
                q.pop_front();
                for(auto adj:graph[top]){
                    if(!visited[adj]){
                        visited[adj]=true;
                        q.emplace_back(adj,len+1);
                    }
                }
            }
            q.clear();
        }
        return maximum;
    }
};
