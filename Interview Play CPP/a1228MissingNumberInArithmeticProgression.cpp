//
//  a1228MissingNumberInArithmeticProgression.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        size_t size = arr.size();
        int i = 0, j = size-1, mid, a_i, d = (arr.back()-arr.front())/(int)size;
        while(i < j) {
            mid = (i+j+1)>>1; // Need to get ceil
            if(arr[mid] != arr.front() + mid*d) j = mid-1;
            else i = mid;
        }
        return arr[i] + d;
    }
};
