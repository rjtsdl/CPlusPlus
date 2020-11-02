//
//  a1642FurthestBuildingYouCanReach.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    
    // [index, bricks, ladders]
    int furthestBuilding(vector<int>& A, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 0; i < A.size() - 1; i++) {
            int d = A[i + 1] - A[i];
            if (d > 0)
                pq.push(-d);
            if (pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return i;
        }
        return A.size() - 1;
    }
};
