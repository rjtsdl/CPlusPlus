//
//  a896MonotonicArray.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() < 2) return true;
        
        bool ret = true;
        for (int i =0; i < A.size()-1; i++) {
             if (A[0] == A.back()) {
                 if (A[i] != A[i+1]) {
                     ret = false;
                     break;
                 }
             } else if (A[0] < A.back()) {
                 if (A[i] > A[i+1]) {
                     ret = false;
                     break;
                 }
             } else {
                 if (A[i] < A[i+1]) {
                     ret = false;
                     break;
                 }
             }
        }
        return ret;
    }
};
