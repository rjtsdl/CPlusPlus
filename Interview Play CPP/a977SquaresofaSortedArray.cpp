//
//  a977SquaresofaSortedArray.cpp
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
    vector<int> sortedSquares(vector<int>& A) {
        
        vector<int> ret;
        
        auto it = upper_bound(A.begin(), A.end(), 0);
        int i = it-A.begin();
        int j = i-1;
        while (j >= 0 || i < A.size()) {
            if (j >= 0 && i < A.size()) {
                if (A[j] + A[i] >= 0) {
                    ret.push_back(A[j] * A[j]);
                    j--;
                } else {
                    ret.push_back(A[i] * A[i]);
                    i++;
                }
            } else if (j >= 0) {
                ret.push_back(A[j] * A[j]);
                j--;
            } else {
                ret.push_back(A[i] * A[i]);
                i++;
            }
        }
        
        return ret;
        
    }
};
