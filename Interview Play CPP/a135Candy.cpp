//
//  a135Candy.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> cc (ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                cc[i] = cc[i-1]+1;
            }
        }
        
        for (int i = ratings.size()-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                cc[i] = max(cc[i], cc[i+1]+1);
            }
        }
        
        
        return accumulate(cc.begin(), cc.end(), 0);
        
    }
};
