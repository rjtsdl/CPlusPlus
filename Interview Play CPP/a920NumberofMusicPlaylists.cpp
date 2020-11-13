//
//  a920NumberofMusicPlaylists.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;
class Solution {
    const int MOD = 1000000007;
public:
    int numMusicPlaylists(int N, int L, int K) {
        long dp[L+1][N+1];
        dp[0][0] = 1;
        
        for (int i = 1; i < L+1; i++) dp[i][0] = 0;
        for (int i = 1; i< N+1; i++) dp[0][i] = 0;
        for (int i = 1; i <= L; ++i)
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = 0;
                dp[i][j] += dp[i-1][j-1] * (N-j+1);
                dp[i][j] += dp[i-1][j] * max(j-K, 0);
                dp[i][j] %= MOD;
            }

        return (int) dp[L][N];
        
    }
};
