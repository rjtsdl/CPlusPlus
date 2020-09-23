//
//  a459RepeatedSubstringPattern.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string needle) {
        vector<int> match(needle.length(), -1);
        int j = -1;
        for (int i = 1; i < needle.length(); i++) {
            while (j>=0 && needle[j+1] != needle[i]) {
                j = match[j];
            }
            
            if (needle[j+1] == needle[i]) {
                j++;
            }
            match[i] = j;
        }
        
        int l = match.back()+1;
        return l != 0 && l % (match.size()-l) == 0;
    }
};
