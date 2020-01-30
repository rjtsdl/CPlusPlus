//
//  a775GlobalandLocalInversions.cpp
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
    bool isIdealPermutation(vector<int>& A) {
        if (A.size() <= 2) return true;
        
        int maxM2 = A[0];
        int maxM1 = max(A[1], A[0]);
        for (int i = 2; i < A.size(); ++i) {
            if (A[i] < maxM2) return false;
            
            maxM2 = maxM1;
            maxM1 = max(maxM1, A[i]);
        }
        
        return true;
    }
};
