//
//  a179LargestNumber.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
            return to_string(a) + to_string(b) < to_string(b) + to_string(a);
        });
        
        string res = "";
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            res += to_string(*it);
        }
        int i = 0;
        while (i < res.size()-1 && res[i] == '0') {i++;}
        
        return res.substr(i);
    }
};
