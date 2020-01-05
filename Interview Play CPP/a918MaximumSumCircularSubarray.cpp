//
//  a918MaximumSumCircularSubarray.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int curMax = A[0];
        int curMin = A[0];
        int maxSum = A[0];
        int minSum = A[0];
        int total = A[0];
        for (int i =1 ; i < A.size(); i++) {
            int a = A[i];
            curMax = max(a, curMax+a);
            maxSum = max(maxSum, curMax);
            if (i < A.size() -1) {
                // we are not getting min subarray (minus the whole array)
                curMin = min(a, curMin+a);
                minSum = min(minSum, curMin);
            }
            total+=a;
        }
        return maxSum > total - minSum ? maxSum : total - minSum;
    }
};
