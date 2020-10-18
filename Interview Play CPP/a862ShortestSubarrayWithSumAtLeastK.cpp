//
//  a862ShortestSubarrayWithSumAtLeastK.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/25/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        
        vector<int> P(A.size() + 1, 0);
        
        for (int i = 1; i < P.size(); i++) {
            P[i] = P[i-1] + A[i-1];
        }
        
        int p = 0;
        int shortLen = P.size();
        list<int> monoq;
        
        for (int i = 0; i < P.size(); i++) {
            
            while (!monoq.empty() && P[monoq.back()] >= P[i]) monoq.pop_back();
            while (!monoq.empty() && P[i] - K >= P[monoq.front()]) {
                shortLen = min(shortLen, i - monoq.front());
                monoq.pop_front();
            }
            monoq.push_back(i);
        }
        
        return shortLen == P.size() ? -1: shortLen;
    }
};
