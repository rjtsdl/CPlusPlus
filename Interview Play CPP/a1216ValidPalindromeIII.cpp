//
//  a1216ValidPalindromeIII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        // longest palindromic subsequence..
        int m = s.length();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        int ans = 1;
        for(int i=0;i<m;i++)
            dp[i][i] = 1;
        for(int i=0;i<m-1;i++){
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
            ans = max(ans, dp[i][i+1]);
        }
        
        for(int len=3;len<=m;len++){
            for(int i=0;i<m-len+1;i++){
                int j = i+len-1;
                if(s[i] == s[j])
                    dp[i][j] = 2+ dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans >= m-k;
    }
};
