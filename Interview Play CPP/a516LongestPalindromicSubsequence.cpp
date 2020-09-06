//
//  a516LongestPalindromicSubsequence.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/5/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int l = s.size();
        vector<vector<int>> dp(l,vector<int>(l,-1));
        return lps(s,0,l-1,dp);
        
    }
    
    int lps(string &s, int i, int j, vector<vector<int>> &dp){
        if(i > j)
            return 0;
        
        if(i == j)
            return dp[i][j] = 1;
        
        if(dp[i][j]==-1){
            if(s[i]==s[j]){
                dp[i][j] = (2+lps(s,i+1,j-1,dp));
            }else{
                dp[i][j] = max(lps(s,i+1,j,dp),lps(s,i,j-1,dp));
            }
        }
        return dp[i][j];
    }
};
