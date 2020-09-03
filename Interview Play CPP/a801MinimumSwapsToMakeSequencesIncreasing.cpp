//
//  a801MinimumSwapsToMakeSequencesIncreasing.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        vector<vector<int>> dp(2, vector<int>(N+1, INT_MAX));
        dp[0][0] = 0;
        dp[1][0] = 0;
        
        for (int i = 0; i < N; ++i) {
            if (i ==0 || (A[i]> A[i-1] && B[i] > B[i-1])) {
                dp[0][i+1] = min(dp[0][i+1], dp[0][i]);
                dp[1][i+1] = min(dp[1][i+1], dp[1][i]+1);
            }
            
            if (i ==0 || (A[i]> B[i-1] && B[i] > A[i-1])) {
                dp[0][i+1] = min(dp[0][i+1], dp[1][i]);
                dp[1][i+1] = min(dp[1][i+1], dp[0][i]+1);
            }
        }
        
        return min(dp[0][N], dp[1][N]);  
    }
};
