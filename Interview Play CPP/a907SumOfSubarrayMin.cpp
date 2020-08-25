//
//  a907SumOfSubarrayMin.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int MOD = 1e9+7;
        int N = A.size();

        // prev has i* - 1 in increasing order of A[i* - 1]
        // where i* is the answer to query j
        stack<int> st;
        vector<int> prev(N,0);
        for (int i = 0; i < N; ++i) {
            while (!st.empty() && A[i] <= A[st.top()]) st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // next has k* + 1 in increasing order of A[k* + 1]
        // where k* is the answer to query j
        
        while (!st.empty()) st.pop();
        vector<int> next(N, 0);
        for (int k = N-1; k >= 0; --k) {
            while (!st.empty() && A[k] < A[st.top()]) st.pop();
            next[k] = st.empty() ? N : st.top();
            st.push(k);
        }

        // Use prev/next array to count answer
        long ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += (i - prev[i]) * (next[i] - i) % MOD * A[i] % MOD;
            ans %= MOD;
        }
        return (int) ans;
        
    }
};
