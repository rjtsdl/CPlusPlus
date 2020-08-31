//
//  a837New21Game.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/31/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    double new21Game(int N, int K, int W) {
       vector<double> dp(N+W+1, 0);
       // dp[x] = the answer when Alice has x points
       for (int k = K; k <= N; ++k)
           dp[k] = 1.0;

       double S = min(N - K + 1, W);
       // S = dp[k+1] + dp[k+2] + ... + dp[k+W]
       for (int k = K - 1; k >= 0; --k) {
           dp[k] = S / W;
           S += dp[k] - dp[k + W];
       }
       return dp[0];
    }
};
