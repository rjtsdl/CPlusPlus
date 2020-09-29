//
//  a1259HandshakesThatDontCross.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfWays(int n) {
        long mod = 1e9 + 7;
        vector<long> dp(n / 2 + 1);
        dp[0] = 1L;
        for (int k = 1; k <= n / 2; ++k) {
            for (int i = 0; i < k; ++i) {
                dp[k] = (dp[k] + dp[i] * dp[k - 1 - i]) % mod;
            }
        }
        return dp[n / 2];
    }
};
