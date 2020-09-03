//
//  a1458MaxDotProductofTwoSubsequences.cpp
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
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size(); int m=nums2.size();
        int dp[n][m];
           dp[n-1][m-1]=nums1[n-1]*nums2[m-1];
        for(int i=m-2;i>=0;i--)
        {
            dp[n-1][i]=max(nums1[n-1]*nums2[i],dp[n-1][i+1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(j==m-1)
                {
                    dp[i][j]=max(nums1[i]*nums2[j],dp[i+1][j]);
                    continue;
                }
                dp[i][j]=max((nums1[i]*nums2[j]+max(dp[i+1][j+1],0)),dp[i][j+1]);
                dp[i][j]=max(dp[i][j],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};
