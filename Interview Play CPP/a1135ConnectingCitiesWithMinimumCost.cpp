//
//  a1135ConnectingCitiesWithMinimumCost.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int find(int x, vector<int>& par){
        if (x != par[x])
            par[x] = find(par[x], par);
        return par[x];
    }
    
    bool union_(int x, int y, vector<int>& par, vector<int>& rank){
        int px = find(x, par), py = find(y, par);
        if (px != py){
            if (rank[px] < rank[py]){
                swap(px, py);
            }
            par[py] = px;
            rank[px] += rank[px] == rank[py];
            return true;
        } else
            return false;
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        if (connections.size() < N - 1)
            return -1;
        sort(begin(connections), end(connections), [](vector<int>& a, vector<int>& b) {return a[2] < b[2];});
        vector<int> par(N + 1, 0);
        for (int i = 1; i < N + 1; ++i) {
            par[i] = i;
        }
        vector<int> rank(N + 1, 0);
        
        int cost = 0, cnt = N;
        for (auto& c: connections) {
            if (union_(c[0], c[1], par, rank)) {
                cnt--, cost += c[2];
                if (cnt == 1)
                    break;
            }
        }
        return cnt == 1 ? cost : -1;
        
    }
};
