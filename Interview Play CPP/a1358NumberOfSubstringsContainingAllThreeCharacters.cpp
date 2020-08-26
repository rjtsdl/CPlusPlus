//
//  a1358NumberOfSubstringsContainingAllThreeCharacters.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), i=0, ans = 0;
        unordered_map<char,int> um;
        for(int j=0; j<n; j++){
            um[s[j]]++;
            while(um['a'] && um['b'] && um['c']){
                um[s[i]]--;
                i++;
            }
            ans += i;
        }
        return ans;
    }
};
