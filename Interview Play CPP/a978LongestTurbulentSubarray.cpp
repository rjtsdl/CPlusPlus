//
//  a978LongestTurbulentSubarray.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/10/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        
        if (A.empty()) {
            return 0;
        }
        int curUp =1;
        int curDown =1;
        int sumUp =1;
        int sumDown =1;
        
        for (int i = 1; i<A.size(); ++i) {
            if (A[i] > A[i-1]) {
                curUp = curDown + 1;
                curDown = 1;
            } else if (A[i] < A[i-1]) {
                curDown = curUp+1;
                curUp=1;
            } else {
                curUp =1;
                curDown = 1;
            }
            
            sumUp = max(sumUp, curUp);
            sumDown = max(sumDown, curDown);
        }
        return max(sumDown, sumUp);  
    }
};
