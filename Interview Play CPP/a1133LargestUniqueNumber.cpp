//
//  a1133LargestUniqueNumber.cpp
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
    int largestUniqueNumber(vector<int>& A) {
        vector<int> count(1001, 0);
        for(const int n: A) ++count[n];
        for(int i = 1000; i >= 0; --i) if(count[i] == 1) return i;
        return -1;
    }
};
