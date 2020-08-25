//
//  a1209RemoveAllAdjacentDupInStringII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (int i = s.length()-1; i >=0; i--) {
            if (st.empty() || st.top().first != s[i]) {
                st.push(make_pair(s[i], 1));
            } else {
                st.push(make_pair(s[i], st.top().second+1));
                if (st.top().second == k) {
                    for (int j =0; j < k; ++j) {
                        st.pop();
                    }
                }
            }
        }
        
        string res = "";
        while (!st.empty()) {
            res += st.top().first;
            st.pop();
        }
        
        return res;
        
    }
};
