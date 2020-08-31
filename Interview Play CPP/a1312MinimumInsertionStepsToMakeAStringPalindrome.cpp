//
//  a1312MinimumInsertionStepsToMakeAStringPalindrome.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        unordered_map<int, int> mem;
        return minInsertionSub(s, 0, s.size()-1, mem);
    }
    
    int minInsertionSub(string& s, int i, int j, unordered_map<int, int>& mem) {
        if (mem.find(i*s.size() + j) != mem.end()) {
            return mem[i*s.size() + j];
        }
        
        if (i >= j) {
            return 0;
        }
        
        
        int ans;
        if (s[i] == s[j]) {
            ans = minInsertionSub(s, i+1, j-1, mem);
        } else {
            ans = 1 + min(minInsertionSub(s, i+1, j, mem), minInsertionSub(s, i, j-1, mem));
        }
        
        mem[i*s.size() + j] = ans;
        return ans;
    }
    
    
};
