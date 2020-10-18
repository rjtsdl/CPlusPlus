//
//  a847ShortestPathVisitingAllNodes.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int status;
        int atNode;
        
        int N = graph.size();
        
        vector<map<int, int>> dp (N);
        
        // 0 -> path len
        // 1 -> end node
        // 2 -> status
        queue<vector<int>> q;
        for (int i =0; i < N; i++) {
            q.push({0, i, 1<<i});
        }
        
        while (!q.empty()) {
            vector<int> t = q.front(); q.pop();
            
            int n = t[1];
            int s = t[2];
            if (dp[n].find(s) != dp[n].end()) continue;
            dp[n][s] = t[0];
            
            if (s == (1<<N) - 1) return t[0];
            
            for (int nei : graph[n]) {
                q.push({t[0]+1, nei, s|(1<<nei)});
            }
        }
        
        return -1;
    }
};

