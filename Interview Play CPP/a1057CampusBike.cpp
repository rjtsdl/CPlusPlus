//
//  a1057CampusBike.cpp
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
    struct Distance {
        int dist;
        int idx_w;
        int idx_b;
    };
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> assignment(workers.size());
        vector<int> assigned_w(workers.size(), 0);
        vector<int> assigned_b(bikes.size(), 0);
        vector<Distance> distances(workers.size() * bikes.size());
        
        //calculate the distances
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                distances[i * bikes.size() + j].dist = getDistance(workers, bikes, i, j);
                distances[i * bikes.size() + j].idx_w = i;
                distances[i * bikes.size() + j].idx_b = j;
            }
        }
        
        //sort the distances
        std::sort(distances.begin(), distances.end(), [](const Distance& a, const Distance& b) {
            if (a.dist == b.dist) {
                return a.idx_w == b.idx_w ? a.idx_b < b.idx_b : a.idx_w < b.idx_w;
            }
            return a.dist < b.dist;
        });
        
        //assign bike to workers
        for (const auto &dist : distances) {
            if (!assigned_w[dist.idx_w] && !assigned_b[dist.idx_b]) {
                assignment[dist.idx_w] = dist.idx_b;
                assigned_w[dist.idx_w] = 1;
                assigned_b[dist.idx_b] = 1;
            }
        }
        
        return assignment;
    }
    
    int getDistance(const vector<vector<int>>& workers, const vector<vector<int>>& bikes, int idx_w, int idx_b) {
        return abs(workers[idx_w][0] - bikes[idx_b][0]) + abs(workers[idx_w][1] - bikes[idx_b][1]);
    }
};
