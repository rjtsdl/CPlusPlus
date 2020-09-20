//
//  a484FindPermutation.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.size() + 1);
        
        for (int i =0; i < res.size(); i++) {
            res[i] = i+1;
        }
        
        auto p = res.begin();
        auto e = next(res.begin(), 1);
        for(char c: s) {
            if (c == 'I') {
                reverse(p, e);
                p = e;
                e++;
            } else if (c == 'D') {
                e++;
            }
        }
        reverse(p, e);
        
        
        return res;
        
    }
};
