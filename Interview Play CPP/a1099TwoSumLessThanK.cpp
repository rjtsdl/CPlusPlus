//
//  a1099TwoSumLessThanK.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K)
    {
        int n = A.size();
                
        if (n <= 1)
            return -1;
        
        int left = 0, right = n-1, gap = INT_MAX, result = -1;
        
        sort(A.begin(), A.end());
            
        while (left < right)
        {
            int sum = A[left] + A[right];
            
            if (sum < K)
            {
                if (K - sum < gap)
                {
                    gap = K - sum;
                    result = sum;
                }
                
                left++;
            }
            else
                right--;
        }
        
        return result;
    }
};
