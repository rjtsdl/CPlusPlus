//
//  a1163LastSubstringInLexicographicalOrder.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/19/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int i = 1, j =0, k=0;
        
        while (i+k < s.size()) {
            if (s[i+k] == s[j+k]) { k++; continue;}
            if (s[i+k] > s[j+k]) {j = i;}
            i++;
            k=0;
        }
        
        return s.substr(j);
    }
};
/*
int main() {
    Solution* sol = new Solution();
    cout << sol->lastSubstring("zrziy") << endl;
    return 0;
}
 */
