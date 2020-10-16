//
//  a764LargestPlusSign.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int dp[N][N];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = 1;
            }
        }
        
        for (vector<int>& mine: mines)
            dp[mine[0]][mine[1]] = 0;
        int ans = 0, count;
        
        for (int r = 0; r < N; ++r) {
            count = 0;
            for (int c = 0; c < N; ++c) {
                count = (dp[r][c] == 0 ? 0 : count+1);
                dp[r][c] = count;
            }
            
            count = 0;
            for (int c = N-1; c >= 0; --c) {
                count = (dp[r][c] == 0 ? 0 : count+1);
                dp[r][c] = min(dp[r][c], count);
            }
        }
        
        for (int c = 0; c < N; ++c) {
            count = 0;
            for (int r = 0; r < N; ++r) {
                count = (dp[r][c] == 0 ? 0 : count+1);
                dp[r][c] = min(dp[r][c], count);
            }
            
            count = 0;
            for (int r = N-1; r >= 0; --r) {
                count = (dp[r][c] == 0 ? 0 : count+1);
                dp[r][c] = min(dp[r][c], count);
                ans = max(ans, dp[r][c]);
            }
        }
        
        return ans;
    }
};
