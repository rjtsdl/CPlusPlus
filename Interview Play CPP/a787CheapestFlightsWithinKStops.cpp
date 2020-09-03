//
//  a787CheapestFlightsWithinKStops.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/1/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> m;
        
        //pq will flip comparator, so if i want ascending, need descending comp, confusing ik lol
        auto comp = [](const vector<int>& a, const vector<int>& b) { return a[1] > b[1]; };
        //vector of type as second param is required when adding custom comp
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> search(comp);
        
        //map of cities to edges
        for (auto f : flights) { m[f[0]].push_back(make_pair(f[1], f[2])); }

        // { val, price, count }
        vector<int> curr = {src, 0, 0};
        while(curr[0] != dst){
            if (curr[2] <= K){
                for (auto adj : m[curr[0]]){
                    /// { val, price, count }
                    search.push({adj.first, adj.second + curr[1], curr[2]});
                }
            }
            if (search.empty()) break;
            auto it = search.top();
            curr = {it[0], it[1], ++it[2]};
            search.pop();
        }
        
        //if price > 0 and we hit dest
        return (curr[1] && curr[0] == dst) ? curr[1] : -1;
    }
};
