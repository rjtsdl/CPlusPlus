//
//  a974SubarraySumsDivisibleByK.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> P(A.size()+1, 0);
        for (int i = 0; i < A.size(); ++i)
            P[i+1] = P[i] + A[i];

        vector<int> count(K, 0);
        for (int x: P)
            count[(x % K + K) % K]++;

        int ans = 0;
        for (int v: count)
            ans += v * (v - 1) / 2;
        return ans;
    }
};
