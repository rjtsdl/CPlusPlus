//
//  a935KnightDialer.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> next(10);
        next[0] = {4,6};
        next[1] = {6,8};
        next[2] = {7,9};
        next[3] = {4,8};
        next[4] = {0,3,9};
        next[5] = {};
        next[6] = {0,1,7};
        next[7] = {2, 6};
        next[8] = {1, 3};
        next[9] = {2, 4};
        
        vector<vector<int>> dp(2, vector<int>(10, 1));
        
        for (int i =0; i < N-1; ++i) {
            fill(dp[~i&1].begin(), dp[~i&1].end(), 0);
            for (int j= 0; j < 10; ++j) {
                for (int nex : next[j]) {
                    dp[~i&1][nex] += dp[i&1][j];
                    dp[~i&1][nex] %= (int)(1e9+7);
                }
            }
        }
        /*
        
        for (int i = 0; i < 2; ++i) {
            cout << "dp " << i << " :";
            for (int j =0; j < 10; ++j) {
                cout << " "<< dp[i][j];
            }
            cout << endl;
        }
         */
        
        int ans = 0;
        for (int j =0; j < 10; ++j) {
            ans += dp[~N&1][j];
            ans %= (int)(1e9+7);
        }
        
        return ans;
    }
};
/*
int main() {
    Solution* sol = new Solution();
    cout << sol->knightDialer(3) << endl;
}
 */
