//
//  a1066CampusBikesII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int findMin(vector<unordered_map<int, int>>& M) {
        int size = M.size();
        vector<pair<int, int>> minVal(size, make_pair(INT_MAX/2, 0));
        minVal[0] = make_pair(0, -1);
        // using Bellman Ford to find the min cost (notice that no negative cycle is possible)
        while (size --) {
            for(int i=0; i<minVal.size(); i++) {
                int val = minVal[i].first;
                for(auto it = M[i].begin(); it != M[i].end(); it++) {
                    int dis = it->second, index = it->first;
                    if (val + dis < minVal[index].first) {
                        minVal[index] = make_pair(val + dis, i);
                    }
                }
            }
        }
        int index = minVal.size() - 1;
        // reverse the graph for bipartite matching
        while (index > 0) {
            int next = minVal[index].second;
            int val = M[next][index];
            M[index][next] = -1 * val;
            M[next].erase(index);
            index = next;
        }
        return minVal.back().first;;
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int wsize = workers.size(), bsize = bikes.size(), size = workers.size() + bikes.size() + 2;
        vector<unordered_map<int, int>> M(size, unordered_map<int,int>());
        // construct the graph
        for(int i=0; i<wsize; i++) {
            M[0][i + 1] = 0;
            for(int j=0; j<bsize; j++) {
                int back = wsize + 1 + j, dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                M[i + 1][back] = dis;
            }
        }
        for(int i=0; i<bsize; i++) {
            int front = wsize + 1 + i, back = wsize + bsize + 1;
            M[front][back] = 0;
        }
        // do bipartite matching
        int ret = 0;
        while (wsize --) {
            ret += findMin(M);
        }
        return ret;
    }
};
