//
//  a1192CriticalConnectionsInANetwork.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/11/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    struct vertex {
        int lowLink;
        int discOrder;
        bool onStack;
    };
    
    vector<vector<int>> tarjan(vector<vector<int>>& G) {
        vector<vertex> V(G.size());
        for (auto& v : V) {
            v.lowLink = -1;
            v.discOrder = -1;
            v.onStack = false;
        }
        
        int order = 0;
        stack<int> S;
        vector<vector<int>> bridges;
        
        for (int i =0 ; i< V.size() ; ++i) {
            if (V[i].discOrder == -1) {
                strongconnect(G, V, S, order, -1, i, bridges);
            }
        }
        return bridges;
    }
    
    void strongconnect(
                       vector<vector<int>>& G,
                       vector<vertex> &V,
                       stack<int>& S,
                       int& order, int parent, int i,
                       vector<vector<int>>& res) {
        V[i].discOrder = order++;
        V[i].lowLink = V[i].discOrder;
        S.push(i);
        V[i].onStack = true;
        
        for (int w : G[i]) {
            if (w == parent) continue;
            if (V[w].discOrder == -1) {
                strongconnect(G, V, S, order, i, w, res);
                V[i].lowLink = min(V[i].lowLink, V[w].lowLink);
            } else if (V[w].onStack) {
                V[i].lowLink = min(V[i].lowLink, V[w].discOrder);
            }
            
            if (V[i].discOrder < V[w].lowLink) {
                res.push_back({i,w});
            }
        }
        
        if (V[i].lowLink == V[i].discOrder) {
            while (S.top() != i) {
                int w = S.top();
                S.pop();
                V[w].onStack = false;
            }
            S.pop();
            V[i].onStack = false;
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> G (n);
        
        for (auto& c : connections) {
            G[c[0]].push_back(c[1]);
            G[c[1]].push_back(c[0]);
        }
        
        return tarjan(G);
    }
    
    
};

int main() {
    vector<vector<int>> connections{{0,1},{1,2},{2,0}, {1,3}, {3,4}, {4,5}, {5,3}};
    Solution* sol = new Solution();
    auto ret = sol->criticalConnections(6, connections);
    return 0;
    
}
