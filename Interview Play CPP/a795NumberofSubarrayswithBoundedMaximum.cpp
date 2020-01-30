//
//  a795NumberofSubarrayswithBoundedMaximum.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return countLessOrEqual(A, R) - countLessOrEqual(A, L-1);
        
    }
    
    int countLessOrEqual(vector<int>& A, int B) {
        int count = 0;
        int cur = 0;
        for (int a : A) {
            if (a <= B) cur++;
            else {
                count += cur * (cur+1) /2 ;
                cur = 0;
            }
        }
        
        if (cur > 0) {
            count += cur * (cur+1) /2 ;
        }
        
        return count;
    }
};
