//
//  a555SplitConcatenatedStrings.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/2/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        for (int i =0; i < strs.size(); i++) {
            string ori = strs[i];
            string rev = strs[i];
            reverse(rev.begin(), rev.end());
            if (rev > ori) strs[i] = rev;
        }
        
        string res = "";
        for (int i = 0; i < strs.size(); i++) {
            string ori = strs[i];
            string rev = strs[i];
            reverse(rev.begin(), rev.end());
            vector<string> tp = {ori, rev};
            for (string& st: tp) {
               for (int k = 0; k < st.size(); k++) {
                   string t = st.substr(k);
                   for (int j = i + 1; j < strs.size(); j++) {t += strs[j];}
                   for (int j = 0; j < i; j++) {t += strs[j];}
                   t += st.substr(0, k);
                   if (t > res) res = t;
               }
           }
        }
        return res;
        
    }
};
