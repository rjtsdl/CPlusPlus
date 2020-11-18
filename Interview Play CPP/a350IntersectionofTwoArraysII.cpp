//
//  a350IntersectionofTwoArraysII.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        nums1.erase(set_intersection(begin(nums1), end(nums1),
            begin(nums2), end(nums2), begin(nums1)), end(nums1));
        return nums1;
    }
};
