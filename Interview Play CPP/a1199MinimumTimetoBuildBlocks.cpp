//
//  a1199MinimumTimetoBuildBlocks.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int b: blocks) {
            pq.push(b);
        }
        
        while (pq.size() > 1) {
            int t = pq.top(); pq.pop();
            int s = pq.top(); pq.pop();
            pq.push(s + split);
        }
        
        return pq.top();
    }
};
