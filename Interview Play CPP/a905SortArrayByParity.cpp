//
//  a905SortArrayByParity.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // three way partition
        
        int i = 0, j = A.size()-1;
        
        while (i < j) {
            if (A[i]%2 == 0) i++;
            else {
                swap(A[i], A[j]);
                j--;
            }
        }
        
        return A;
    }
};
