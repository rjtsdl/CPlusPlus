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
        int N = A.size();
        vector<long> P(N+1);
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + (long) A[i];

        // Want smallest y-x with P[y] - P[x] >= K
        int ans = N+1; // N+1 is impossible
        list<int> monoq; //opt(y) candidates, as indices of P

        for (int y = 0; y < P.size(); ++y) {
            // Want opt(y) = largest x with P[x] <= P[y] - K;
            while (!monoq.empty() && P[y] <= P[monoq.back()]) monoq.pop_back();
            while (!monoq.empty() && P[y] >= P[monoq.front()] + K) {
                ans = min(ans, y-monoq.front());
                monoq.pop_front();
            }

            monoq.push_back(y);
        }

        return ans < N+1 ? ans : -1;
    }
};
