//
//  a229MajorityElementII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //corner case
        if(nums.empty()) return {};
         
        //variables
        int ct1 = 0, ct2 = 0, candidate1 = 0, candidate2 = 1;
        vector<int> res;
        
        for(int num: nums){
            if(num == candidate1){
                ++ct1;
            } else if(num == candidate2){
                ++ct2;
            } else if(!ct1) {
                ct1 = 1;
                candidate1 = num;
            } else if(!ct2){
                ct2 = 1;
                candidate2 = num;
            } else {
                --ct1;
                --ct2;
            }
        }
        
        //check if the 2 candidates are valid
        ct1 = ct2 = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == candidate1) ++ct1;
            else if(nums[i] == candidate2) ++ct2;
        }
        
        //if so, push them back
        if(ct1 > nums.size()/3) res.push_back(candidate1);
        if(ct2 > nums.size()/3) res.push_back(candidate2);
        
        return res;
    }
};

