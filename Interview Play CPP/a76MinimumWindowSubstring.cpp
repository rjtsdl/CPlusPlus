//
//  a76MinimumWindowSubstring.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/13/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> tc(59, 0);
        vector<int> rc(59, 0);
        // 'a' - 'Z' = 7
        
        for (char c : t) tc[c-'A']++;
        int rmatch = 0;
        int tsize = t.size();
        string res = "";
        
        for (int j = 0, i = 0; j < s.size(); j++) {
            rc[s[j]-'A']++;
            if (rc[s[j]-'A'] <= tc[s[j]-'A']) rmatch++;
            while (rmatch == tsize && i <= j) {
                if (res.empty() || j-i+1 < res.size()) res = s.substr(i, j-i+1);
                rc[s[i]-'A']--;
                if (rc[s[i]-'A'] < tc[s[i]-'A']) rmatch--;
                i++;
            }
        }
        
        return res;
    }
};
