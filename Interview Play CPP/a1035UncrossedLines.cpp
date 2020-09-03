//
//  a1035UncrossedLines.cpp
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
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1 , vector<int>(B.size()+1));
        for(int i=0;i<=A.size();i++){
            for(int j=0;j<=B.size();j++){
                if(i==0 || j ==0)
                    dp[i][j]=0;
                else if(A[i-1]==B[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[A.size()][B.size()];
    }
};
