//
//  a1168OptimizeWaterDistributioninaVillage.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class UnionFind {
    public:
    int total_cost = 0;
    vector<int> parents;
    
    UnionFind(int n) {
        parents.resize(n);
        for(int i=0; i < n; ++i) parents[i] = i;
    }
    int find(int i) {
        
        if (i == parents[i])    return i;
        parents[i] = find(parents[i]);
        return parents[i];
    }
    void unite(int i, int j, int cost) {
        
        int pi = find(i);
        int pj = find(j);
        if(pi != pj) {
            parents[pi] = pj;
            total_cost += cost;
        }
        
    }
};

class Solution {
    static bool comp(vector<int> a, vector<int> b) {
        return a[2] < b[2];
    }
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        if (n == 0) return 0;
        if (pipes.size() == 0) return accumulate(wells.begin(), wells.end(), 0);
        
        for (int i = 0; i < wells.size(); i++) {
            pipes.push_back({0, i + 1, wells[i]});
        }
        sort(pipes.begin(), pipes.end(), comp);
        UnionFind uf = UnionFind(n + 1);
        for (int i = 0; i < pipes.size(); i++) {
            uf.unite(pipes[i][0], pipes[i][1], pipes[i][2]);
        }
        return uf.total_cost;
    }
};
