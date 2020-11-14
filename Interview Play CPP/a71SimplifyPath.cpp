//
//  a71SimplifyPath.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/13/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        string cur = "";
        
        for (int i =0; i < path.size(); i++) {
            if (path[i] != '/') {
                cur += path[i];
                continue;
            }
        
            if (cur.empty() || cur == ".") {
                
            }
            else if (cur == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(cur);
            }
            cur = "";
        }
        
        if (st.empty()) return "/";
        string ret = "";
        while (!st.empty()) {
            ret = "/" + st.top() + ret; st.pop();
        }
        
        return ret;
    }
};
