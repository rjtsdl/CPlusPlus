//
//  a1027LongestArithmeticSubsequence.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        
         int ans = 1;
         vector<vector<int>> DP(n, vector<int>(1001, 1));
         
         for(int i = 1; i < n; i++)
         {
             for(int j = 0; j < i; j++)
             {
                 DP[i][500 + (A[i] - A[j])] = max(DP[i][500 + (A[i] - A[j])], DP[j][500 + (A[i] - A[j])] + 1);
                 ans = max(ans, DP[i][500 + (A[i] - A[j])]);
             }
         }
         return ans;
    }
};
