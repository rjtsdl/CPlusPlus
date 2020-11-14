//
//  a60PermutationSequence.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/12/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> nums(n);
        for (int i =1; i <= n; i++) nums[i-1] = i;
        
        vector<int> facto(n, 1);
        for (int i = 1; i < n; i++) facto[i] = i* facto[i-1];
        k--;
        
        string ret = "";
        for (int i = n-1; i >=0; i--) {
            int permNum = k / facto[i];
            ret += to_string(nums[permNum]);
            nums.erase(nums.begin() + permNum);
            k = k % facto[i];
        }
        
        return ret;
    }
};


Rj19890201-

