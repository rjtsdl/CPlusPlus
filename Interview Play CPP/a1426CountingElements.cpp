//
//  a1426CountingElements.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        return count_if(arr.begin(), arr.end(), [&](int x){return s.count(x+1);});
    }
};
