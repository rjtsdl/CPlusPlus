//
//  a261GraphValidTree.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        vector<list<int>> grf(n);
        
        for (vector<int>& e : edges) {
            int f = e[0];
            int t = e[1];
            grf[f].push_back(t);
            grf[t].push_back(f);
        }
        
        vector<bool> visited(n, false);
        
        int startNode = 0;
        int counter = 0;
        dfs(grf, startNode, visited, counter);
        
        return counter == n;
        
    }
    
    void dfs(vector<list<int>>& grf, int startNode, vector<bool>& visited, int& counter) {
        if (visited[startNode]) return;
        visited[startNode] = true;
        counter++;
        for (int a : grf[startNode]) {
            dfs(grf, a, visited, counter);
        }
    }
};
